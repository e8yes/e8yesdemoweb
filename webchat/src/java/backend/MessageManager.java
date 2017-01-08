/*
 * Copyright (C) 2017 davis
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
package backend;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.Collections;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author davis
 */
public class MessageManager {
        
        private DBConnector     m_conn;
        
        public MessageManager(DBConnector conn, FriendshipManager fs_mgr) {
                m_conn = conn;
                try {
                        Statement s = m_conn.get_connection().createStatement();
                        s.executeUpdate("create table if not exists message_manager("
                                + "uid_b integer,"
                                + "uid_a integer,"
                                + "fid integer,"
                                + "t timestamp(0) default current_timestamp,"
                                + "has_read boolean,"
                                + "msg text,"
                                + "unique key (uid_b, uid_a, t),"
                                + "primary key (fid, t),"
                                + "foreign key (uid_a, uid_b) references " 
                                        + FriendshipManager.get_entity_name() + FriendshipManager.get_key_name() 
                                        + " on delete cascade) "
                                + " default character set=utf8;");
                } catch (SQLException ex) {
                        Logger.getLogger(MessageManager.class.getName()).log(Level.SEVERE, null, ex);
                }
        }
        
        public boolean new_message(Message msg) {
                Timestamp t = new Timestamp(msg.get_timestamp());
                try {
                        PreparedStatement ps = m_conn.get_connection().prepareStatement(
                                "insert into message_manager (uid_a, uid_b, fid, t, has_read, msg) "
                                + " values (" + msg.sender() + "," 
                                              + msg.receiver() + ","
                                              + msg.get_fid() + "," 
                                              + "?," 
                                              + msg.has_read() + ","
                                              + "?);");
                        ps.setTimestamp(1, t);
                        ps.setString(2, msg.get_content());
                        int r = ps.executeUpdate();
                        return r == 1;
                } catch (SQLException ex) {
                        Logger.getLogger(MessageManager.class.getName()).log(Level.SEVERE, null, ex);
                        return false;
                }
        }
        
        public boolean clear_unread_state(int receiver, long timestamp) {
                Timestamp t = new Timestamp(timestamp);
                try {
                        PreparedStatement ps = m_conn.get_connection().prepareStatement(
                                "update message_manager set has_read = true "
                                + " where has_read = false and uid_b = " + receiver + " and t <= ?;");
                        ps.setTimestamp(1, t);
                        int q = ps.executeUpdate();
                        return true;
                } catch (SQLException ex) {
                        Logger.getLogger(MessageManager.class.getName()).log(Level.SEVERE, null, ex);
                        return false;
                }
        }
        
        public ArrayList<Message> get_messages(int fid, int n) {
                try {
                        Statement s = m_conn.get_connection().createStatement();
                        ResultSet result = s.executeQuery("select * from message_manager "
                                + "where fid = " + fid
                                + " order by t desc "
                                + " limit " + n + ";");
                        ArrayList<Message> msgs = new ArrayList<>();
                        while (result.next()) {
                                int sender = result.getInt("uid_a");
                                int receiver = result.getInt("uid_b");
                                int afid = result.getInt("fid");
                                long timestamp = result.getTimestamp("t").getTime();
                                boolean has_read = result.getBoolean("has_read");
                                String content = result.getString("msg");
                                msgs.add(new Message(sender, receiver, afid, timestamp, has_read, content));
                        }
                        Collections.reverse(msgs);
                        return msgs;
                } catch (SQLException ex) {
                        Logger.getLogger(MessageManager.class.getName()).log(Level.SEVERE, null, ex);
                        return null;
                }
        }
        
        public ArrayList<Message> get_received_unread_messages(int uid_receiver) {
                try {
                        Statement s = m_conn.get_connection().createStatement();
                        ResultSet result = s.executeQuery("select * from message_manager "
                                + " where has_read = false and uid_b = " + uid_receiver
                                + " order by t asc;");
                        ArrayList<Message> msgs = new ArrayList<>();
                        while (result.next()) {
                                int sender = result.getInt("uid_a");
                                int receiver = result.getInt("uid_b");
                                int fid = result.getInt("fid");
                                long timestamp = result.getTimestamp("t").getTime();
                                boolean has_read = result.getBoolean("has_read");
                                String content = result.getString("msg");
                                msgs.add(new Message(sender, receiver, fid, timestamp, has_read, content));
                        }
                        return msgs;
                } catch (SQLException ex) {
                        Logger.getLogger(MessageManager.class.getName()).log(Level.SEVERE, null, ex);
                        return null;
                }
        }
}
