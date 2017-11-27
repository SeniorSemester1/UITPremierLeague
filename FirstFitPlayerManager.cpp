#include "FirstFitPlayerManager.h"

FirstFitPlayerManager::FirstFitPlayerManager()
{
    headNum = NONE_OF_NEXT_RECORD_AVAILABLE;
}

bool FirstFitPlayerManager::addPlayer(PlayerRecord newPlayer) {
    if (isPlayerExist(newPlayer)) {
        return false;
    }
    if (headNum == -1) {
        playersJoined.push_back(newPlayer);
    }
    else {
        int nextAvailPos = headNum;
        std::list<PlayerRecord>::iterator ite;

        do {
            ite = getNextAvailRecordByPosition(nextAvailPos); //go to the next available position
            //*ite là đọc giá trị ở địa chỉ pointer ite trỏ tới

            PlayerRecord* currRecord = &*ite;
            int redundantSpaces = currRecord->getSize() - newPlayer.getSize();
            if (redundantSpaces >= 0) //compare to insert
            {
                //delete value in current record
                //insert newPlayer to current record
                //update headNum
                currRecord->setName(newPlayer.getName());
                headNum = currRecord->getNextAvailRecordPos();
                currRecord->setNextAvailRecordPos(-1);
            }
            else
            {
                //go to next available position
                nextAvailPos = currRecord->getNextAvailRecordPos();
                //too long => add tail
                if(nextAvailPos == -1)
                    playersJoined.push_back(newPlayer);
            }

        } while (nextAvailPos != -1);
        //firstFitPlayerRecord->setName(newPlayer.getName());
    }
    return true;
}
