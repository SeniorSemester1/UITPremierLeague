#include "League.h"

League::League(int seasonNum, int mode)
{
    this->seasonNum = seasonNum;
    this->mode = mode;
}

void League::addSeason(Season* season) {
    seasons.push_back(*season);
}
