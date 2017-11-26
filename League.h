#ifndef LEAGUE_H
#define LEAGUE_H
#include <ClubManager.h>
#include <ClubRecord.h>

class League
{
private:
    int seasonNum;
    int mode;
    ClubManager* joinedClub;
    std::list<ClubRecord> leftClub;

public:
    League(int , int );
    int getSeasonNum() {return seasonNum;}
    int getMode() {return mode;}
    ClubManager* getClubManager() {return joinedClub;}

};

#endif // LEAGUE_H
