#ifndef LEAGUE_H
#define LEAGUE_H
#include <vector>
#include <Season.h>

class League
{
private:
    int seasonNum;
    int mode;
    std::vector<Season> seasons;
public:
    League(int , int );
    int getSeasonNum() {return seasonNum;}
    int getMode() {return mode;}
    void addSeason(Season* );
};

#endif // LEAGUE_H
