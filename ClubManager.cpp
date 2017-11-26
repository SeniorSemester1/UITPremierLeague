#include "ClubManager.h"
#include "ClubRecord.h"

#include <algorithm>
#include <string>


ClubManager::ClubManager()
{

}

void ClubManager::setHeadNum(int header) {
    this->headNum = header;
}

ClubRecord ClubManager::getClub(ClubRecord aClub) {

}
bool ClubManager::addClub(ClubRecord newClub) {

    if(headNum == -1) // doesn't have any avail space, add new to the end of the list
    {
        clubsJoined.push_back(newClub);
        return true;
    }
    else
    {
        std::list<ClubRecord>::iterator it;
        it = clubsJoined.begin();
        std::advance(it, headNum);  // replacement at first avail space

        ClubRecord club_record_temp = *it;
        int RRN_temp = club_record_temp.getRRN(); // next avail space index
        headNum = RRN_temp;

        *it = newClub; // replacement by new club
        return true;
    }
    return false;

}
bool ClubManager::removeClub(ClubRecord delClub) {

    std::list<ClubRecord>::iterator it; // create list iterator
    it = clubsJoined.begin();

    for(int i = 0; i < (int)clubsJoined.size(); i++)
    {
        std::advance(it, i); // getting an instant

        if(delClub == &*it)
        {
            std::string str_temp = it->getName();

            if(headNum == -1)
            {
                headNum = i;
                str_temp = "*-1" + str_temp;

                it->setName(str_temp);
            }
            else
            {
                it->setRRN(headNum);

                str_temp = std::to_string(headNum) + str_temp;
                str_temp = "*" + str_temp;
            headNum = i;
            }

            return true;
        }
    }
    return false;
}
void ClubManager::defragment() {

    if(headNum == -1)
        return;

    std::list<ClubRecord>::iterator it; // create list iterator
    it = clubsJoined.begin();

    while (nullptr != &*it) {
       if(it->getName()[0] == '*') // search avail space
           it = clubsJoined.erase(it); // delete avail space and move to next space
       else
           ++it; // move to next space
    }
    return;
}

bool ClubManager::isClubExist(ClubRecord aClub) {

    std::list<ClubRecord>::iterator it; // create list iterator
    it = clubsJoined.begin();

    for(int i = 0; i < (int)clubsJoined.size(); i++)
    {
        std::advance(it, i);

        if(aClub == &*it)
            return true;
    }
    return false;
}
