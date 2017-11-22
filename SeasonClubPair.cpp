#include "SeasonClubPair.h"

SeasonClubPair::SeasonClubPair(Season* season, Club* club)
{
    this->season = season;
    this->club = club;
}

bool SeasonClubPair::operator==(SeasonClubPair* anotherSCPair) {
    if (this->season == anotherSCPair->getSeason() && this->club == anotherSCPair->getClub())
        return true;
    return false;
}

bool SeasonClubPair::operator !=(SeasonClubPair* anotherSCPair) {
    if (this->season == anotherSCPair->getSeason() && this->club == anotherSCPair->getClub())
        return false;

    return true;
}
