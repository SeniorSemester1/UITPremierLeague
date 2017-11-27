#ifndef LEAGUEMANAGER_H
#define LEAGUEMANAGER_H
#include <string>
#include <fstream>
#include <ClubRecord.h>
#include <PlayerRecord.h>
#include <League.h>
#include <DataReader.h>
#include <DataWriter.h>

class LeagueManager {
private:
    League* league;
    DataReader* reader;
    DataWriter* writer;
    void readSeason();
    void readClub(int );
    void readPlayer(int );
public:
    LeagueManager();
    void readData(std::string path);
    void writeClub2File(std::string path);
    void writePlayer2File();
    void writePlayer2File(int );
};

#endif // LEAGUEMANAGER_H
