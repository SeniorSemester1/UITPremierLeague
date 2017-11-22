#ifndef LEAGUEMANAGER_H
#define LEAGUEMANAGER_H
#include <string>
#include <fstream>
#include <vector>
#include <Club.h>
#include <Player.h>
#include <Season.h>
#include <League.h>
#include <DataReader.h>
#include <SeasonEnrollment.h>
#include <ClubEnrollment.h>

class LeagueManager {
private:
    std::string mode;
    std::vector<League> leagues;
    std::fstream readStrm;
    std::string path;
    DataReader* reader;
    void readSeason(Season* currSeason);
public:
    LeagueManager(std::string path);
    void readData();

};

#endif // LEAGUEMANAGER_H
