#include "PlayerManager.h"


PlayerRecord PlayerManager::getPlayer(PlayerRecord aPlayer) {
    for (std::list<PlayerRecord>::iterator ci = players.begin(); ci != players.end(); ci++) {
        if ((PlayerRecord)*ci == aPlayer)
            return (PlayerRecord)*ci;
    }
}

bool PlayerManager::isPlayerExist(PlayerRecord aPlayer) {
    for (std::list<PlayerRecord>::iterator ci = players.begin(); ci != players.end(); ci++) {
        if ((PlayerRecord)*ci == aPlayer)
            return true;
    }
    return false;
}

bool PlayerManager::removePlayer(PlayerRecord aPlayer) {

}
void PlayerManager::defragment() {

}
