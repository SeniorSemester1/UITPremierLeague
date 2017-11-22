#ifndef SEASONENROLLMENT_H
#define SEASONENROLLMENT_H
#include <vector>
#include <SeasonClubPair.h>
#include <Season.h>
#include <Club.h>

class SeasonEnrollment
{
private:
    std::vector<SeasonClubPair> pairs;
public:
    SeasonEnrollment();
    bool addPairs(SeasonClubPair* );
    bool removePairs(SeasonClubPair* );
    std::vector<Club> getClubsJoinedSeason(Season* aSeason);
    std::vector<Season> getSeasonsClubJoined(Club* aClub);
};

#endif // SEASONENROLLMENT_H
