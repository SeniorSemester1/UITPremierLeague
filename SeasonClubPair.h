#ifndef SEASONCLUBPAIR_H
#define SEASONCLUBPAIR_H
#include <Season.h>
#include <Club.h>

class SeasonClubPair
{
private:
    Season* season;
    Club* club;
public:
    SeasonClubPair(Season*, Club*);
    SeasonClubPair* getPair() { return this;}
    Season* getSeason() { return season;}
    Club* getClub() { return club;}
    bool operator ==(SeasonClubPair* anotherSCPair);
    bool operator !=(SeasonClubPair* anotherSCPair);
};

#endif // SEASONCLUBPAIR_H
