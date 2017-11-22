#ifndef CLUBENROLLMENT_H
#define CLUBENROLLMENT_H
#include <vector>
#include <ClubPlayerPair.h>
#include <Player.h>
#include <Club.h>

class ClubEnrollment
{
private:
    std::vector<ClubPlayerPair> pairs;
public:
    ClubEnrollment();
    bool addPairs(ClubPlayerPair* );
    bool removePairs(ClubPlayerPair* );
    std::vector<Player> getPlayersJoinedClub(Club* );
    std::vector<Club> getClubsPlayerJoined(Player* );
};

#endif // CLUBENROLLMENT_H
