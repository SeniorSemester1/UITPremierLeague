#include "ClubRecord.h"
#include <BestFitPlayerManager.h>
#include <FirstFitPlayerManager.h>

ClubRecord::ClubRecord(std::string name) {
    this->name = name;
}


ClubRecord::ClubRecord(std::string name, int recordMode) {
    this->name = name;
    if (recordMode == 1)
        this->playerManager = new FirstFitPlayerManager();
    else if (recordMode == 0)
        this->playerManager = new BestFitPlayerManager();
}

bool ClubRecord::operator==(ClubRecord* anotherClub) {
    if (name == anotherClub->getName())
        return true;
    return false;
}

bool ClubRecord::operator !=(ClubRecord* anotherClub) {
    if (name == anotherClub->getName())
        return false;
    return true;
}
