#include "ClubManager.h"
#include "ClubRecord.h"

#include <string>

#define NONE_NEXT_REMOVED_RECORD_AVAILABLE -1

ClubManager::ClubManager()
{
    headNum = NONE_NEXT_REMOVED_RECORD_AVAILABLE;
}

void ClubManager::setHeadNum(int header) {
    this->headNum = header;
}

ClubRecord ClubManager::getClubJoined(ClubRecord aClub) {
    for (std::list<ClubRecord>::const_iterator ite = clubsJoined.begin(); ite != clubsJoined.end(); ite++) {
        ClubRecord currClub = (ClubRecord)*ite;
        if (currClub == aClub)
            return currClub;
    }
}

bool ClubManager::isInClubLeft(ClubRecord aClub) {
    for (std::list<ClubRecord>::const_iterator ite = clubsLeft.begin(); ite != clubsLeft.end(); ite++) {
        ClubRecord currClub = (ClubRecord)*ite;
        if (currClub == aClub)
            return true;
    }
    return false;
}

ClubRecord ClubManager::getClubsLeft(ClubRecord aClub) {
    for (std::list<ClubRecord>::const_iterator ite = clubsLeft.begin(); ite != clubsLeft.end(); ite++) {
        ClubRecord currClub = (ClubRecord)*ite;
        if (currClub == aClub)
            return currClub;
    }
}

bool ClubManager::addClub(ClubRecord newClub) {
    if (isClubExist(newClub))
        return false;

    if (isInClubLeft(newClub)) {
        newClub = getClubsLeft(newClub);
        clubsLeft.remove(newClub);
    }

    if(headNum == NONE_NEXT_REMOVED_RECORD_AVAILABLE) { // doesn't have any avail space, add new to the end of the list
        newClub.setRRN(clubsJoined.size());
        clubsJoined.push_back(newClub);
    }
    else
    {
        std::list<ClubRecord>::iterator it;
        it = clubsJoined.begin();
        std::advance(it, headNum);  // replacement at first avail space

        headNum = it->getNextAvailRecord();

        *it = newClub; // replacement by new club
    }
    return true;

}
bool ClubManager::removeClub(ClubRecord delClub) {
    if (!isClubExist(delClub))
        return false;

    std::list<ClubRecord>::iterator ite; // create list iterator
    ite = clubsJoined.begin();

    for(ite; ite != clubsJoined.end(); ite++)
    {
        ClubRecord* currClub = &*ite;
        if(delClub == *currClub)
        {
            //move club left to another list
            clubsLeft.push_back(*currClub);
            ite->setPlayerManager(NULL);

            if(headNum == NONE_NEXT_REMOVED_RECORD_AVAILABLE)
            {
                currClub->setName("*-1");
                currClub->setNextAvailRecord(NONE_NEXT_REMOVED_RECORD_AVAILABLE);
            }
            else
            {
                currClub->setName("*" + std::to_string(headNum));
                currClub->setNextAvailRecord(headNum);

            }
            headNum = currClub->getRRN();
        }
    }
    return true;
}
void ClubManager::defragment() {

    if(headNum == NONE_NEXT_REMOVED_RECORD_AVAILABLE)
        return;

    std::list<ClubRecord>::iterator ite; // create list iterator
    ite = clubsJoined.begin();

    int index = 0;
    while (ite != clubsJoined.end()) {
       if(ite->getName()[0] == '*') { // search avail space
           clubsLeft.push_back((ClubRecord)*ite);
           ite = clubsJoined.erase(ite); // delete avail space and move to next space
       }
       else {
           ite->setRRN(index);
           index++;
           ite++; // move to next space
       }
    }
    headNum = NONE_NEXT_REMOVED_RECORD_AVAILABLE;
}

bool ClubManager::isClubExist(ClubRecord aClub) {

    std::list<ClubRecord>::const_iterator ite; // create list iterator
    ite = clubsJoined.begin();

    for(ite; ite != clubsJoined.end(); ite++)
    {
        ClubRecord currClub = *ite;
        if(aClub == currClub)
            return true;
    }
    return false;
}
