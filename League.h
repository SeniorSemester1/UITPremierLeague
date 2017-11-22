#ifndef LEAGUE_H
#define LEAGUE_H
#include <vector>
#include <SeasonEnrollment.h>
#include <ClubEnrollment.h>

class League
{
private:
    int seasonNum;
    int mode;
    SeasonEnrollment* seasons;
    ClubEnrollment* clubs;
public:
    League(int , int );
    int getSeasonNum() {return seasonNum;}
    int getMode() {return mode;}
    SeasonEnrollment* getSeasons() {return seasons;}
    ClubEnrollment* getClubs() {return clubs;}
};

#endif // LEAGUE_H
