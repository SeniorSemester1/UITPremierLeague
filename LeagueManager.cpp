#include <LeagueManager.h>
#include <DataReader.h>
#include <iostream>

LeagueManager::LeagueManager(std::string path) {
    this->path = path;
    readStrm.open(path, std::ios::in);
    reader = new DataReader(readStrm);
}

void LeagueManager::readData() {
    leagues.push_back(*reader->readLeague());
    try {
        for (int idxSeason = 0; idxSeason < leagues[0].getSeasonNum(); idxSeason++) {
            Season* aSeason = new Season(idxSeason);
            readSeason(aSeason);
        }
    } catch (std::invalid_argument& ia) {

    } catch (std::out_of_range& ofr) {

    }
}

void LeagueManager::readSeason(Season* currSeason) {
    try {
        SeasonChangeWrapper* seasonChange = reader->readSeasonChange();
        for (int idxClub = 0; idxClub < seasonChange->getClubChange(); idxClub++) {
            ClubChangeWrapper* clubChange = reader->readClub();
            Club* aClub = new Club(clubChange->getName());
            SeasonClubPair* seasonClubPair = new SeasonClubPair(currSeason, aClub);
            switch (clubChange->getMode()) {
            case 1:
                if (leagues[0].getSeasons()->addPairs(seasonClubPair)) {

                    std::cout << "Add successful" << std::endl;
                }
                break;
            case 0:
                if (leagues[0].getSeasons()->removePairs(seasonClubPair)) {
                    std::cout << "Remove successful" << std::endl;
                }
                break;
            }

        }
        for (int idxPlayer = 0; idxPlayer < seasonChange->getPlayerChange(); idxPlayer++) {
            PlayerChangeWrapper* playerChange = reader->readPlayer();
            Club* aClub = new Club(playerChange->getClubName());
            Player* aPlayer = new Player(playerChange->getPlayerName());
            ClubPlayerPair* clubPlayerPair = new ClubPlayerPair(aClub, aPlayer);
            switch (playerChange->getMode()) {
            case 1:
                if (leagues[0].getClubs()->addPairs(clubPlayerPair)) {
                    std::cout << "Add successful" << std::endl;
                }
                break;
            case 0:
                if (leagues[0].getClubs()->removePairs(clubPlayerPair)) {
                    std::cout << "Remove successful" << std::endl;
                }
                break;
            }
        }
    } catch (std::invalid_argument& ia) {

    } catch (std::out_of_range& ofr) {

    }
}
