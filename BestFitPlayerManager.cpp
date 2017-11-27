#include "BestFitPlayerManager.h"
#include <limits>

BestFitPlayerManager::BestFitPlayerManager()
{
    headNum = NONE_OF_NEXT_RECORD_AVAILABLE;
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
        PlayerRecord* bestFitPlayerRecord = NULL;
        PlayerRecord* previousPlayerRecord = NULL;
        std::list<PlayerRecord>::iterator ite;

        do {
            ite = getNextAvailRecordByPosition(nextAvailPos);
            PlayerRecord* currPlayerRecord = &*ite;
            int redundantSpaces = currPlayerRecord->getSize() - newPlayer.getSize();
            if ( redundantSpaces >= 0 && redundantSpaces < bestFitSize) {
                bestFitPlayerRecord = currPlayerRecord;
                bestFitSize = redundantSpaces;

            }
            previousPlayerRecord = currPlayerRecord;
            nextAvailPos = currPlayerRecord->getNextAvailRecordPos();
        } while (nextAvailPos != -1);

        if (bestFitPlayerRecord == NULL) {
            playersJoined.push_back(newPlayer);
        } else {
            bestFitPlayerRecord->setName(newPlayer.getName());
            previousPlayerRecord->setNextAvailRecordPos(bestFitPlayerRecord->getNextAvailRecordPos());
        }
    }
    return true;
}
