#include "Player.h"

bool Player::operator ==(Player anotherPlayer) {
    if (name == anotherPlayer.getName())
        return true;
    return false;
}

bool Player::operator !=(Player anotherPlayer) {
    if (*this == anotherPlayer)
        return false;
    return true;
}


