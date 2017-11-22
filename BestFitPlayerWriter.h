#ifndef BESTFITPLAYERWRITER_H
#define BESTFITPLAYERWRITER_H
#include <PlayerWriter.h>

class BestFitPlayerWriter : public PlayerWriter
{
public:
    BestFitPlayerWriter();
    void addPlayer() override;
    void removePlayer() override;
    void defragment() override;
};

#endif // BESTFITPLAYERWRITER_H
