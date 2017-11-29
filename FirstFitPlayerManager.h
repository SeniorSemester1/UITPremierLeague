#ifndef FIRSTFITPLAYERMANAGER_H
#define FIRSTFITPLAYERMANAGER_H
#include <PlayerManager.h>

class FirstFitPlayerManager : public PlayerManager
{
public:
    FirstFitPlayerManager();
    bool addPlayer(PlayerRecord ) override;
    //std::list<PlayerRecord>::iterator getNextAvailRecordByPosition(int );
};

#endif // FIRSTFITPLAYERMANAGER_H
