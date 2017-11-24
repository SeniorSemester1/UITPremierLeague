#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class PlayerRecord
{
private:
    std::string name;
    int size;
public:
    PlayerRecord(std::string );
    std::string getName() {return name;}
    int getSize() {return size;}
    void setName(std::string);
    void setSize(int );
    bool operator ==(PlayerRecord );
    bool operator !=(PlayerRecord );
};

#endif // PLAYER_H
