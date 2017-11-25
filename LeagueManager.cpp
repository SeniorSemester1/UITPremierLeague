#include <LeagueManager.h>
#include <DataReader.h>
#include <iostream>


LeagueManager::LeagueManager(std::string path) {
    this->path = path;
    readStrm.open(path, std::ios::in);
    reader = new DataReader(readStrm);
}

void LeagueManager::readData() {
    league = reader->readLeague();
    try {
        for (int idxSeason = 0; idxSeason < league->getSeasonNum(); idxSeason++) {
            readSeason();
        }
    } catch (std::invalid_argument& ia) {

    } catch (std::out_of_range& ofr) {

    }
}

void LeagueManager::readSeason() {
    try {
        SeasonChangeWrapper* seasonChange = reader->readSeasonChange();
        for (int idxClub = 0; idxClub < seasonChange->getClubChange(); idxClub++) {
            ClubChangeWrapper* clubChange = reader->readClub();
            ClubRecord* aClub = new ClubRecord(clubChange->getName(), league->getMode());
            switch (clubChange->getMode()) {
            case 1:
                if (league->getClubManager()->addClub(*aClub)) {

                    std::cout << "Add successful" << std::endl;
                }
                break;
            case 0:
                if (league->getClubManager()->removeClub(*aClub)) {
                    std::cout << "Remove successful" << std::endl;
                }
                break;
            default:
                break;
            }
            delete(aClub);
        }
        for (int idxPlayer = 0; idxPlayer < seasonChange->getPlayerChange(); idxPlayer++) {
            PlayerChangeWrapper* playerChange = reader->readPlayer();
            ClubRecord* aClub = new ClubRecord(playerChange->getClubName());
            if (league->getClubManager()->isClubExist(*aClub)) {
                PlayerRecord* aPlayer = new PlayerRecord(playerChange->getPlayerName());
                switch (playerChange->getMode()) {
                case 1:
                    if (league->getClubManager()->getClub(*aClub).getPlayerManager()->addPlayer(*aPlayer)) {
                        std::cout << "Add successful" << std::endl;
                    }
                    break;
                case 0:
                    if (league->getClubManager()->getClub(*aClub).getPlayerManager()->removePlayer(*aPlayer)) {
                        std::cout << "Remove successful" << std::endl;
                    }
                    break;
                default:
                    break;
                }
                delete(aClub);
            }
            delete(aClub);
        }
    } catch (std::invalid_argument& ia) {

    } catch (std::out_of_range& ofr) {

    }

}
