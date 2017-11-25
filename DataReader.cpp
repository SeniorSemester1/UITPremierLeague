#include "DataReader.h"
#include <iostream>

DataReader::DataReader(std::string path)
{
    this->readStrm.open(path, std::ios::in);
}

League* DataReader::readLeague() {
    std::string seasonStr, modeStr;
    std::getline(readStrm, seasonStr, ' ');
    std::getline(readStrm, modeStr, '\n');
    std::cout << seasonStr << " " << modeStr << std::endl;
    int seasonInt = std::stoi(seasonStr);
    int modeInt = std::stoi(modeStr);
    League* league = new League(seasonInt, modeInt);
    return league;
}

SeasonChangeWrapper* DataReader::readSeasonChange() {
    std::string clubChangeStr, playerChangeStr;
    std::getline(readStrm, clubChangeStr, ' ');
    std::getline(readStrm, playerChangeStr, '\n');
    std::cout << clubChangeStr << " " << playerChangeStr << std::endl;
    int clubChangeInt = std::stoi(clubChangeStr);
    int playerChangeInt = std::stoi(playerChangeStr);
    SeasonChangeWrapper* seasonChange = new SeasonChangeWrapper(clubChangeInt, playerChangeInt);
    return seasonChange;
}

ClubChangeWrapper* DataReader::readClub()
{
    std::string modeStr, name;
    std::getline(readStrm, modeStr, ' ');
    std::getline(readStrm, name, '\n');
    std::cout << modeStr << " " << name << std::endl;
    int modeInt = std::stoi(modeStr);
    ClubChangeWrapper* wrapper = new ClubChangeWrapper(modeInt, name);
    return wrapper;
}

PlayerChangeWrapper* DataReader::readPlayer() {
    std::string modeStr, playerName, clubName;
    std::getline(readStrm, modeStr, ' ');
    std::getline(readStrm, clubName, ' ');
    std::getline(readStrm, playerName, '\n');
    std::cout << modeStr << " " << clubName << " " << playerName << std::endl;
    int modeInt = std::stoi(modeStr);
    PlayerChangeWrapper* wrapper = new PlayerChangeWrapper(modeInt, playerName, clubName);
    return wrapper;
}

void DataReader::closeStream() {
    readStrm.close();
}


