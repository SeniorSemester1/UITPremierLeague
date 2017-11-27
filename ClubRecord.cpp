#include "ClubRecord.h"
#include <BestFitPlayerManager.h>
#include <FirstFitPlayerManager.h>

#define FIRST_FIT_MODE 1
#define BEST_FIT_MODE 0

ClubRecord::ClubRecord(std::string name) {
    this->name = name;
    this->nextAvalRecord = -1;
}

void ClubRecord::setName(std::string name)
{
    this->name = name;
}

void ClubRecord::setRRN(std::int32_t x)
{
    this->RRN = x;
}

void ClubRecord::setNextAvailRecord(int nextAvailRecord) {
    this->nextAvalRecord = nextAvailRecord;
}

void ClubRecord::setPlayerManager(PlayerManager* newPlayerManager) {
    this->playerManager = newPlayerManager;
}

ClubRecord::ClubRecord(std::string name, int recordMode) {
    this->name = name;
    if (recordMode == FIRST_FIT_MODE)
        this->playerManager = new FirstFitPlayerManager();
    else if (recordMode == BEST_FIT_MODE)
        this->playerManager = new BestFitPlayerManager();
}

bool ClubRecord::operator==(ClubRecord anotherClub) {
    if (name == anotherClub.getName())
        return true;
    return false;
}

bool ClubRecord::operator !=(ClubRecord anotherClub) {
    if (name == anotherClub.getName())
        return false;
    return true;
}
