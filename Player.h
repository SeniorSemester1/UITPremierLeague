#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class Player
{
private:
    std::string name;
public:
    Player(std::string name) { this->name = name;}
    Player(Player* aPlayer) { this->name = aPlayer->name;}
    std::string getName() {return name;}
    bool operator ==(Player );
    bool operator !=(Player );
};

#endif // PLAYER_H
