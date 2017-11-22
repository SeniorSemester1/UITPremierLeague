#include "ClubEnrollment.h"

ClubEnrollment::ClubEnrollment()
{

}

bool ClubEnrollment::addPairs(ClubPlayerPair* pair) {
    pairs.push_back(*pair);
    unsigned int i = 0;
    while (pairs[i] != pair)
        i++;
    if (i == pairs.size() - 1) {
        return true;
    }
    pairs.pop_back();
    return false;
}

bool ClubEnrollment::removePairs(ClubPlayerPair* pair) {
    pairs.push_back(*pair);
    unsigned int i = 0;
    while (pairs[i] != pair)
        i++;
    if (i == pairs.size() - 1) {
        return false;
    }
    pairs.pop_back();
    pairs.erase(pairs.begin() + i);
    return true;
}

std::vector<Player> ClubEnrollment::getPlayersJoinedClub(Club* aClub) {
    std::vector<Player> playersJoined;
    for (unsigned int i = 0; i < pairs.size(); i++) {
        if (pairs[i].getClub() == aClub)
            playersJoined.push_back(pairs[i].getPlayer());
    }
    return playersJoined;
}

std::vector<Club> ClubEnrollment::getClubsPlayerJoined(Player* aPlayer) {
    std::vector<Club> clubsJoined;
    for (unsigned int i = 0; i < pairs.size(); i++) {
        if (pairs[i].getPlayer() == aPlayer)
            clubsJoined.push_back(pairs[i].getClub());
    }
    return clubsJoined;
}
