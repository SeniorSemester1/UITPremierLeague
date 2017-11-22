#include "Club.h"

bool Club::operator==(Club* anotherClub) {
    if (name == anotherClub->getName())
        return true;
    return false;
}

bool Club::operator !=(Club* anotherClub) {
    if (this == anotherClub)
        return false;
    return true;
}
