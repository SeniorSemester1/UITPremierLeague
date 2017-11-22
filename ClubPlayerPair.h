#ifndef TEAMPLAYERPAIR_H
#define TEAMPLAYERPAIR_H
#include <Club.h>
#include <Player.h>

class ClubPlayerPair
{
private:
    Club* club;
    Player* player;
public:
    ClubPlayerPair(Club*, Player*);
    ClubPlayerPair* getPair() {return this;}
    Club* getClub() {return club;}
    Player* getPlayer() {return player;}
    bool operator ==(ClubPlayerPair* );
    bool operator !=(ClubPlayerPair* );
};

#endif // TEAMPLAYERPAIR_H
