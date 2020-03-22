package org.e8yes.service.identity;

/** Defines the identity context of a user -- Who is that and what can it do? */
public class Identity {

  public long userId;

  public Identity(long userId) {
    this.userId = userId;
  }

  @Override
  public int hashCode() {
    return Long.hashCode(userId);
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null) {
      return false;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    final Identity other = (Identity) obj;
    return this.userId == other.userId;
  }
}
