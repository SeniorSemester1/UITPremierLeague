#ifndef CLUB_H
#define CLUB_H
#include <string>
#include <fstream>
#include <list>

#include <PlayerRecord.h>
#include <PlayerManager.h>

class ClubRecord
{
private:
    std::string name;
    int RRN;
    PlayerManager* playerManager;
public:
    ClubRecord();
    ClubRecord(std::string );
    ClubRecord(std::string, int );
    std::string getName() {return name;}
    int getRRN() {return RRN;}
    PlayerManager* getPlayerManager() {return playerManager;}

    void setName(std::string );
    void setRRN(int RRN);
    bool operator ==(ClubRecord* );
    bool operator !=(ClubRecord* );
};

#endif // CLUB_H
