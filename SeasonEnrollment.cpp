#include "SeasonEnrollment.h"

SeasonEnrollment::SeasonEnrollment()
{

}
bool SeasonEnrollment::addPairs(SeasonClubPair* pair) {
    pairs.push_back(*pair);
    int i = 0;
    while (pairs[i] != pair)
        i++;
    if (i == pairs.size() - 1) {
        return true;
    }
    pairs.pop_back();
    return false;
}

bool SeasonEnrollment::removePairs(SeasonClubPair* pair) {
    pairs.push_back(*pair);
    int i = 0;
    while (pairs[i] != pair)
        i++;
    if (i == pairs.size() - 1) {
        return false;
    }
    pairs.pop_back();
    pairs.erase(pairs.begin() + i);
    return true;
}

std::vector<Club> SeasonEnrollment::getClubsJoinedSeason(Season* aSeason) {
    std::vector<Club> clubsJoined;
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].getSeason() == aSeason)
            clubsJoined.push_back(pairs[i].getClub());
    }
    return clubsJoined;
}

std::vector<Season> SeasonEnrollment::getSeasonsClubJoined(Club* aClub) {
    std::vector<Season> seasonsJoined;
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].getClub() == aClub)
            seasonsJoined.push_back(pairs[i].getSeason());
    }
    return seasonsJoined;
}
