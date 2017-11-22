#ifndef FIRSTFITPLAYERWRITER_H
#define FIRSTFITPLAYERWRITER_H
#include <PlayerWriter.h>

class FirstFitPlayerWriter : public PlayerWriter
{
public:
    FirstFitPlayerWriter();
    void addPlayer() override;
    void removePlayer() override;
    void defragment() override;
};

#endif // FIRSTFITPLAYERWRITER_H
