#include "PlayerManager.h"


PlayerRecord PlayerManager::getPlayer(PlayerRecord aPlayer) {
    for (std::list<PlayerRecord>::iterator ci = playersJoined.begin(); ci != playersJoined.end(); ci++) {
        if ((PlayerRecord)*ci == aPlayer)
            return (PlayerRecord)*ci;
    }
}

void PlayerManager::setHeader(int header) {
    this->headNum = header;
}

bool PlayerManager::isPlayerExist(PlayerRecord aPlayer) {
    for (std::list<PlayerRecord>::iterator ci = playersJoined.begin(); ci != playersJoined.end(); ci++) {
        if ((PlayerRecord)*ci == aPlayer)
            return true;
    }
    return false;
}

bool PlayerManager::removePlayer(PlayerRecord aPlayer) {

}
void PlayerManager::defragment() {

}
