#include "DataWriter.h"
#include <fstream>

DataWriter::DataWriter(League* league)
{
    this->league = league;
}

void DataWriter::writeClub2File(std::string path) {
    std::fstream writeStrm;
    writeStrm.open(path, std::ios::out);

    std::list<ClubRecord> clubs = league->getClubManager()->getClubsList();
    writeStrm << league->getClubManager()->getHeadNum() << " ";
    for (std::list<ClubRecord>::iterator it = clubs.begin(); it != clubs.end(); it++) {
        writeStrm << ((ClubRecord)*it).getName() << "|";
    }

}

void DataWriter::writePlayer2File(std::string path, ClubRecord club) {
    std::fstream writeStrm;
    writeStrm.open(path, std::ios::out);

    std::list<PlayerRecord> players = league->getClubManager()->getClub(club).getPlayerManager()->getPlayersList();
    writeStrm << league->getClubManager()->getClub(club).getPlayerManager()->getHeader() << " ";
    for (std::list<PlayerRecord>::iterator it = players.begin(); it != players.end(); it++) {
        writeStrm << ((PlayerRecord)*it).getName() << "|";
    }
}
