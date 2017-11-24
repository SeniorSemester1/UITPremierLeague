#ifndef SEASON_H
#define SEASON_H
#include <list>
#include <ClubRecord.h>
#include <ClubManager.h>

class Season
{
private:
    int Id;
    ClubManager* clubManager;
public:
    Season(int seasonId);
    Season(Season* aSeason);
    int getId() {return Id;}
    ClubManager* getClubManager() { return clubManager; }
    bool operator ==(Season* );
    bool operator !=(Season* );
};

#endif // SEASON_H
