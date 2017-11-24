#include "Season.h"

Season::Season(int seasonId) {
    Id = seasonId;
    clubManager = new ClubManager;
}
Season::Season(Season* aSeason) {
    this->Id = aSeason->getId();
    clubManager = new ClubManager;
}

bool Season::operator ==(Season* anotherSeason) {
    if (this->Id == anotherSeason->getId())
        return true;
    return false;
}

bool Season::operator !=(Season* anotherSeason) {
    if (this == anotherSeason)
        return false;
    return true;
}
