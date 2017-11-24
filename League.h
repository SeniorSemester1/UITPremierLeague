#ifndef LEAGUE_H
#define LEAGUE_H
#include <vector>
#include <ClubManager.h>

class League
{
private:
    int seasonNum;
    int mode;
    ClubManager* clubManager;
public:
    League(int , int );
    int getSeasonNum() {return seasonNum;}
    int getMode() {return mode;}
    ClubManager* getClubManager() {return clubManager;}
};

#endif // LEAGUE_H
