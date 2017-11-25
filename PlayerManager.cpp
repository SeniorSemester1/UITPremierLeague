#include "PlayerManager.h"

PlayerRecord PlayerManager::getPlayer(PlayerRecord aPlayer) {
    for (std::list<PlayerRecord>::iterator ci = playersJoined.begin(); ci != playersJoined.end(); ci++) {
        if ((PlayerRecord)*ci == aPlayer)
            return (PlayerRecord)*ci;
    }
}

void PlayerManager::setHeader(int header) {
    this->headNum = header;
}

bool PlayerManager::isPlayerExist(PlayerRecord aPlayer) {
    for (std::list<PlayerRecord>::iterator ci = playersJoined.begin(); ci != playersJoined.end(); ci++) {
        if ((PlayerRecord)*ci == aPlayer)
            return true;
    }
    return false;
}

bool PlayerManager::removePlayer(PlayerRecord delPlayer) {
    int position = BYTE_OF_HEADER_AND_SPACE;
    for (std::list<PlayerRecord>::iterator ci = playersJoined.begin(); ci != playersJoined.end(); ci++) {
        PlayerRecord* currPlayer = &*ci;
        if (delPlayer == *currPlayer) {
            currPlayer->setName("*" + std::to_string(headNum));
            currPlayer->setNextAvailRecordPos(headNum);
            this->headNum = position;
            return true;
        }
        position += currPlayer->getSize() + BYTE_OF_PLAYER_SIZE;
    }
    return false;
}


void PlayerManager::defragment() {
    for (std::list<PlayerRecord>::iterator ci = playersJoined.begin(); ci != playersJoined.end(); ci++) {
        PlayerRecord* currPlayer = &*ci;
        if (currPlayer->getName()[0] == '*') {
            playersJoined.erase(ci);
        }
        currPlayer->setSize(currPlayer->getName().size());
    }

}

