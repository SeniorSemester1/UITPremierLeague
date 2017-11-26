#include "FirstFitPlayerManager.h"

FirstFitPlayerManager::FirstFitPlayerManager()
{

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
        int firstFitSize = INT32_MAX;
        PlayerRecord* firstFitPlayerRecord;
        std::list<PlayerRecord>::iterator ite;

        do {
            ite = getNextAvailRecordByPosition(nextAvailPos); //go to the next available position
            //*ite là đọc giá trị ở địa chỉ pointer ite trỏ tới

            PlayerRecord* currRecord = &*ite;

            if (currRecord->getSize() - newPlayer.getSize() < firstFitSize) //compare to insert
            {
                //delete value in current record
                //insert newPlayer to current record
                //update headNum
                firstFitPlayerRecord = currRecord; //cap nhat lai vi tri
                firstFitPlayerRecord->setName(newPlayer.getName());
                firstFitSize = currRecord->getSize() - newPlayer.getSize(); //cap nhat lai firstFitSize.
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

std::list<PlayerRecord>::iterator FirstFitPlayerManager::getNextAvailRecordByPosition(int nextAvalPos) {
    int position = BYTE_OF_HEADER_AND_SPACE; //2 bytes
    for (std::list<PlayerRecord>::iterator ite = playersJoined.begin(); ite != playersJoined.end(); ite++) {
        if (position == nextAvalPos)
            return ite;
        position += ((PlayerRecord)*ite).getSize() + BYTE_OF_PLAYER_SIZE;
    }
}
