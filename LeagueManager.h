#ifndef LEAGUEMANAGER_H
#define LEAGUEMANAGER_H
#include <string>
#include <fstream>
#include <ClubRecord.h>
#include <PlayerRecord.h>
#include <League.h>
#include <DataReader.h>

class LeagueManager {
private:
    std::string mode;
    League* league;
    std::fstream readStrm;
    std::string path;
    DataReader* reader;
    void readSeason();
public:
    LeagueManager(std::string path);
    void readData();

};

#endif // LEAGUEMANAGER_H
