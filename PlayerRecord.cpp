#include "PlayerRecord.h"

PlayerRecord::PlayerRecord(std::string name) {
    this->name = name;
    this->size = name.size();
}

void PlayerRecord::setName(std::string name) {
    this->name = name;
}

void PlayerRecord::setSize(int size) {
    this->size = size;
}

void PlayerRecord::setNextAvailRecordPos(int nextAvailRecordPos) {
    this->nextAvailRecordPos = nextAvailRecordPos;
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


