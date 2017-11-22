#include "ClubPlayerPair.h"

ClubPlayerPair::ClubPlayerPair(Club* club, Player* player)
{
    this->club = club;
    this->player = player;
}

bool ClubPlayerPair::operator ==(ClubPlayerPair* anotherCPP) {
    if (this->club == anotherCPP->getClub() && this->player == anotherCPP->getPlayer())
        return true;
    return false;
}

bool ClubPlayerPair::operator !=(ClubPlayerPair* anotherCPP) {
    if (this->club == anotherCPP->getClub() && this->player == anotherCPP->getPlayer())
        return false;
    return true;
}
