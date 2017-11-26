#ifndef BESTFITPLAYERMANAGER_H
#define BESTFITPLAYERMANAGER_H
#include <PlayerManager.h>

class BestFitPlayerManager : public PlayerManager
{
public:
    BestFitPlayerManager();
    bool addPlayer(PlayerRecord ) override;
};

#endif // BESTFITPLAYERMANAGER_H
