/**
 * e8yes demo web server.
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
package org.e8yes.service.file;

import com.auth0.jwt.JWT;
import com.auth0.jwt.JWTVerifier;
import com.auth0.jwt.algorithms.Algorithm;
import com.auth0.jwt.exceptions.JWTVerificationException;
import com.auth0.jwt.interfaces.DecodedJWT;
import java.time.Instant;
import java.util.Date;
import org.e8yes.exception.AccessDeniedException;
import org.e8yes.jwtprovider.JwtUtil;
import org.e8yes.service.FileAccessMode;
import org.e8yes.service.StorageVolume;
import org.e8yes.service.identity.Identity;
import org.e8yes.sql.connection.ConnectionReservoirInterface;

/** Validates file access. */
public class FileAccessValidator {

  private static final String FILE_VIEWER_ID_KEY = "I";
  private static final String FILE_VOLUME_KEY = "V";
  private static final String FILE_PATH_KEY = "P";
  private static final String FILE_ACCESS_MODE_KEY = "A";
  private static final long EXPIRY_AFTER_MILLIS = 1000 * 60 * 10;

  public static class FileAccessLocation {
    public StorageVolume vol;
    public String path;

    public FileAccessLocation(StorageVolume vol, String path) {
      this.vol = vol;
      this.path = path;
    }

    @Override
    public int hashCode() {
      int hash = 7;
      hash = hash * 23 + vol.hashCode();
      hash = hash * 23 + path.hashCode();
      return hash;
    }

    @Override
    public boolean equals(Object obj) {
      final FileAccessLocation other = (FileAccessLocation) obj;
      return this.vol == other.vol && this.path.equals(other.path);
    }
  }

  public static class FileAccessToken {
    byte[] jwtToken;
  }

  /**
   * Sign a token for a user to allow access to the specified file location.
   *
   * @param viewer Identity of the user who is allowed to use this token.
   * @param location File location this token is valid for.
   * @param accessMode Access mode of the location this token is valid for.
   * @param alg JWT signature algorithm.
   * @return An access token for the specified location.
   */
  public static FileAccessToken signAccessToken(
      Identity viewer, FileAccessLocation location, FileAccessMode accessMode, Algorithm alg) {
    long expiryTimestampMillis = Instant.now().plusMillis(EXPIRY_AFTER_MILLIS).toEpochMilli();
    String base64Token =
        JWT.create()
            .withClaim(FILE_VIEWER_ID_KEY, viewer.userId)
            .withClaim(FILE_VOLUME_KEY, location.vol.getNumber())
            .withClaim(FILE_PATH_KEY, location.path)
            .withClaim(FILE_ACCESS_MODE_KEY, accessMode.getNumber())
            .withExpiresAt(new Date(expiryTimestampMillis))
            .sign(alg);

    FileAccessToken accessToken = new FileAccessToken();
    accessToken.jwtToken = JwtUtil.convertToByteArray(base64Token);

    return accessToken;
  }

  /**
   * Validate access to a location using a specified access mode through a file access token.
   *
   * @param viewer Identity of the viewer to validate against.
   * @param accessMode Expected access mode to the file location.
   * @param accessToken The access token to be validated.
   * @param verifier JWT verification algorithm.
   * @return Locate of the file the token permits access to.
   * @throws JWTVerificationException
   * @throws AccessDeniedException
   */
  public static FileAccessLocation validateTokenAccess(
      Identity viewer, FileAccessMode accessMode, FileAccessToken accessToken, JWTVerifier verifier)
      throws JWTVerificationException, AccessDeniedException {
    String jwtToken = JwtUtil.convertFromByteArray(accessToken.jwtToken);
    DecodedJWT decoded = verifier.verify(jwtToken);

    long tokenViewerId = decoded.getClaim(FILE_VIEWER_ID_KEY).asLong();
    if (viewer.userId != tokenViewerId) {
      throw new AccessDeniedException("The access token is for a different viewer.");
    }

    FileAccessMode tokenFileAccessMode =
        FileAccessMode.forNumber(decoded.getClaim(FILE_ACCESS_MODE_KEY).asInt());
    if (tokenFileAccessMode != accessMode && tokenFileAccessMode != FileAccessMode.FAM_READWRITE) {
      throw new AccessDeniedException(
          "Requires accessMode=" + accessMode + ", but got=" + tokenFileAccessMode);
    }

    return new FileAccessLocation(
        StorageVolume.forNumber(decoded.getClaim(FILE_VOLUME_KEY).asInt()),
        decoded.getClaim(FILE_PATH_KEY).asString());
  }

  public static void validateDirectAccess(
      Identity viewer,
      FileAccessLocation location,
      FileAccessMode accessMode,
      ConnectionReservoirInterface dbConn)
      throws IllegalArgumentException {}
}