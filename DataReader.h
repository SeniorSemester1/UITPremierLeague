#ifndef DATAREADER_H
#define DATAREADER_H
#include <fstream>
#include <League.h>
#include <SeasonChangeWrapper.h>
#include <PlayerChangeWrapper.h>
#include <ClubChangeWrapper.h>

class DataReader
{
private:
    std::fstream* readStrm;
public:
    DataReader(std::fstream& readStrm);
    League* readLeague();
    SeasonChangeWrapper* readSeasonChange();
    ClubChangeWrapper* readClub();
    PlayerChangeWrapper* readPlayer();
};

#endif // DATAREADER_H
