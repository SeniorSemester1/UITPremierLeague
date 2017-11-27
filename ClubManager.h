#ifndef CLUBMANAGER_H
#define CLUBMANAGER_H
#include <list>
#include <ClubRecord.h>

class ClubManager
{
private:
    int headNum;
    std::list<ClubRecord> clubsJoined;
    std::list<ClubRecord> clubsLeft;
    bool isInClubLeft(ClubRecord );
    ClubRecord getClubsLeft(ClubRecord );
public:
    ClubManager();
    std::list<ClubRecord> getClubsList() { return clubsJoined; }
    ClubRecord getClubJoined(ClubRecord );
    int getHeadNum() {return headNum;}
    void setHeadNum(int );

    bool isClubExist(ClubRecord );
    bool addClub(ClubRecord );
    bool removeClub(ClubRecord );
    void defragment();
};

#endif // CLUBMANAGER_H
