#include "League.h"

League::League(int seasonNum, int mode)
{
    this->seasonNum = seasonNum;
    this->mode = mode;
    clubManager = new ClubManager();
}
