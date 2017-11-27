#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <list>
#include <PlayerRecord.h>


class PlayerManager
{
protected:
    int headNum;
    std::list<PlayerRecord> playersJoined;

    const int BYTE_OF_PLAYER_SIZE = 1;
    const int BYTE_OF_HEADER_AND_SPACE = 2;
    const int NONE_OF_NEXT_RECORD_AVAILABLE = -1;

    std::list<PlayerRecord>::iterator getNextAvailRecordByPosition(int );
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
