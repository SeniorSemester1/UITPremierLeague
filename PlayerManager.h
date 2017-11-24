#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <list>
#include <PlayerRecord.h>

class PlayerManager
{
private:
    int headNum;
    std::list<PlayerRecord> playersJoined;
public:
    std::list<PlayerRecord> getPlayersList() { return playersJoined; }
    bool isPlayerExist(PlayerRecord );
    PlayerRecord getPlayer(PlayerRecord );
    int getHeader() {return headNum;}
    void setHeader(int );

    virtual bool addPlayer(PlayerRecord ) = 0;
    bool removePlayer(PlayerRecord );
    void defragment();

};

#endif // PLAYERMANAGER_H
