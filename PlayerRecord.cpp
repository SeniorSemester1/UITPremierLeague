#include "PlayerRecord.h"

PlayerRecord::PlayerRecord(std::string name) {
    this->name = name;
}

bool PlayerRecord::operator ==(PlayerRecord anotherPlayer) {
    if (name == anotherPlayer.getName())
        return true;
    return false;
}

bool PlayerRecord::operator !=(PlayerRecord anotherPlayer) {
    if (name == anotherPlayer.getName())
        return false;
    return true;
}


