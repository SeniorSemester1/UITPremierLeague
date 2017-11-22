#ifndef CLUB_H
#define CLUB_H
#include <string>
#include <fstream>
class Club
{
private:
    std::string name;
public:
    Club(std::string name) { this->name = name; }
    Club(Club* aClub) { this->name = aClub->name; }
    std::string getName() {return name;}
    bool operator ==(Club* );
    bool operator !=(Club* );
};

#endif // CLUB_H
