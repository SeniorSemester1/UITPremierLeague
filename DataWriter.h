#ifndef DATAWRITER_H
#define DATAWRITER_H
#include <League.h>

class DataWriter
{
private:
    League* league;
public:
    DataWriter(League* league);
    void writeClub();
    void writePlayer();

};

#endif // DATAWRITER_H
