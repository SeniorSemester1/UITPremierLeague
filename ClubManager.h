#ifndef CLUBMANAGER_H
#define CLUBMANAGER_H
#include <list>
#include <ClubRecord.h>

class ClubManager
{
private:
    std::list<ClubRecord> clubsJoined;
public:
    ClubManager();
    std::list<ClubRecord> getClubsList() { return clubsJoined; }
    ClubRecord getClub(ClubRecord );
    bool isClubExist(ClubRecord );
    bool addClub(ClubRecord );
    bool removeClub(ClubRecord );
    void defragment();
};

#endif // CLUBMANAGER_H
