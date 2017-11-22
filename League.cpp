#include "League.h"

League::League(int seasonNum, int mode)
{
    this->seasonNum = seasonNum;
    this->mode = mode;
    seasons = new SeasonEnrollment();
    clubs = new ClubEnrollment();
}
