#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <list>
#include <PlayerRecord.h>

class PlayerManager
{
private:
    std::list<PlayerRecord> players;
public:
    std::list<PlayerRecord> getPlayersList() { return players; }
    bool isPlayerExist(PlayerRecord );
    PlayerRecord getPlayer(PlayerRecord );
    virtual bool addPlayer(PlayerRecord ) = 0;
    bool removePlayer(PlayerRecord );
    void defragment();

};

#endif // PLAYERMANAGER_H
