#include "DataWriter.h"
#include <fstream>

DataWriter::DataWriter(League* league)
{
    this->league = &*league;
}

void DataWriter::writeClub2File(std::string path) {
    std::fstream writeStrm;
    writeStrm.open(path, std::ios::out);

    std::list<ClubRecord> clubs = league->getClubManager()->getClubsList();
    writeStrm << league->getClubManager()->getHeadNum() << " ";
    for (std::list<ClubRecord>::iterator it = clubs.begin(); it != --clubs.end(); it++) {
        writeStrm << ((ClubRecord)*it).getName() << "|";
    }
    writeStrm << clubs.back().getName();
    writeStrm.close();
}

void DataWriter::writePlayer2File(ClubRecord club) {
    std::fstream writeStrm;
    writeStrm.open(club.getName() + ".TXT", std::ios::out);

    std::list<PlayerRecord> players = league->getClubManager()->getClubJoined(club).getPlayerManager()->getPlayersList();
    writeStrm << league->getClubManager()->getClubJoined(club).getPlayerManager()->getHeader() << " ";
    for (std::list<PlayerRecord>::iterator it = players.begin(); it != --players.end(); it++) {
        writeStrm << it->getSize() << it->getName() << "|";
    }
    writeStrm << players.back().getSize() << players.back().getName();
    writeStrm.close();
}

void DataWriter::writePlayer2File(ClubRecord club, int season) {
    std::fstream writeStrm;
    writeStrm.open(club.getName() + "." + std::to_string(season), std::ios::out);

    std::list<PlayerRecord> players = league->getClubManager()->getClubJoined(club).getPlayerManager()->getPlayersList();
    writeStrm << league->getClubManager()->getClubJoined(club).getPlayerManager()->getHeader() << " ";
    for (std::list<PlayerRecord>::iterator it = players.begin(); it != --players.end(); it++) {
        writeStrm << it->getSize() << it->getName() << "|";
    }
    writeStrm << players.back().getSize() << players.back().getName();
    writeStrm.close();
}
