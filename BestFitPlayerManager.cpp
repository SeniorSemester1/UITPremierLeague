#include "BestFitPlayerManager.h"
#include <limits>

BestFitPlayerManager::BestFitPlayerManager()
{

}


bool BestFitPlayerManager::addPlayer(PlayerRecord newPlayer) {
    if (isPlayerExist(newPlayer)) {
        return false;
    }
    if (headNum == -1) {
        playersJoined.push_back(newPlayer);
    }
    else {

        int nextAvailPos = headNum;
        int bestFitSize = INT32_MAX;
        PlayerRecord* bestFitPlayerRecord;
        PlayerRecord* previousPlayerRecord;
        std::list<PlayerRecord>::iterator ite;

        do {
            ite = getNextAvailRecordByPosition(nextAvailPos);
            PlayerRecord* currRecord = &*ite;
            if (currRecord->getSize() - newPlayer.getSize() < bestFitSize) {
                bestFitPlayerRecord = currRecord;
                bestFitSize = currRecord->getSize() - newPlayer.getSize();
                previousPlayerRecord = currRecord;
            }
            nextAvailPos = currRecord->getNextAvailRecordPos();
        } while (nextAvailPos != -1);

        bestFitPlayerRecord->setName(newPlayer.getName());
        previousPlayerRecord->setNextAvailRecordPos(bestFitPlayerRecord->getNextAvailRecordPos());
    }
    return true;
}


std::list<PlayerRecord>::iterator BestFitPlayerManager::getNextAvailRecordByPosition(int nextAvalPos) {
    int position = BYTE_OF_HEADER_AND_SPACE;
    for (std::list<PlayerRecord>::iterator ite = playersJoined.begin(); ite != playersJoined.end(); ite++) {
        if (position == nextAvalPos)
            return ite;
        position += ((PlayerRecord)*ite).getSize() + BYTE_OF_PLAYER_SIZE;
    }
}
