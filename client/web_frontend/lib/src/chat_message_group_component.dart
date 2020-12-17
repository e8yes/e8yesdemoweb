/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

import 'package:angular/angular.dart';
import 'package:angular/di.dart';
import 'package:angular_forms/angular_forms.dart';
import 'package:demoweb_app/src/basic/context.dart';
import 'package:demoweb_app/src/chat_message_component.dart';
import 'package:demoweb_app/src/date_component.dart';
import 'package:demoweb_app/src/proto_dart/chat_message.pb.dart';
import 'package:demoweb_app/src/proto_dart/service_chat_message.pbgrpc.dart';
import 'package:demoweb_app/src/service/chat_message_service_interface.dart';
import 'package:fixnum/fixnum.dart';

@Component(
    selector: "chat-message-group",
    templateUrl: "chat_message_group_component.html",
    styleUrls: [
      "chat_message_group_component.css"
    ],
    directives: [
      coreDirectives,
      formDirectives,
      DateComponent,
      ChatMessageComponent
    ],
    exports: [
      ChatMessageThread
    ])
class ChatMessageGroupComponent {
  @Input()
  bool creationMode;
  @Input()
  Int64 messageChannelId;
  @Input()
  ChatMessageThread chatMessageThread;

  String newMessageThreadTitle;

  ChatMessageServiceInterface _chatMessageService;

  ChatMessageGroupComponent(this._chatMessageService) {}

  void addNewMessageThread() {
    CreateChatMessageThreadRequest request = CreateChatMessageThreadRequest();
    request.channelId = messageChannelId;
    if (newMessageThreadTitle != null) {
      request.threadTitle = newMessageThreadTitle;
    }
    request.threadType = ChatMessageThreadType.CMTT_TEMPORAL;

    _chatMessageService
        .createChatMessageThread(request, credentialStorage.loadSignature())
        .then((CreateChatMessageThreadResponse res) {});
  }
}
