#ifndef SEASON_H
#define SEASON_H
#include <vector>
#include <Club.h>

class Season
{
private:
    int Id;
public:
    Season(int seasonId) { this->Id = seasonId;}
    Season(Season* aSeason) { this->Id = aSeason->Id;}
    int getId() {return Id;}
    bool operator ==(Season* );
    bool operator !=(Season* );
};

#endif // SEASON_H
