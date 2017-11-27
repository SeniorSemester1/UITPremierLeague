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

std::list<PlayerRecord>::iterator PlayerManager::getNextAvailRecordByPosition(int nextAvalPos) {
    int position = BYTE_OF_HEADER_AND_SPACE;
    for (std::list<PlayerRecord>::iterator ite = playersJoined.begin(); ite != playersJoined.end(); ite++) {
        if (position == nextAvalPos)
            return ite;
        position += ((PlayerRecord)*ite).getSize() + BYTE_OF_PLAYER_SIZE;
    }
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
    std::list<PlayerRecord>::iterator ite; // create list iterator
    ite = playersJoined.begin();

    while (ite != playersJoined.end()) {
       if(ite->getName()[0] == '*') { // search avail space
           ite = playersJoined.erase(ite); // delete avail space and move to next space
       }
       else {
           ite++; // move to next space
       }
    }
    headNum = NONE_OF_NEXT_RECORD_AVAILABLE;
}

