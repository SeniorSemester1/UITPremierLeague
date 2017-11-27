#include <LeagueManager.h>
#include <DataReader.h>
#include <iostream>

#define ADD 1
#define REMOVE 0

LeagueManager::LeagueManager() {

}

void LeagueManager::readData(std::string path) {
    reader = new DataReader(path);
    league = reader->readLeague();
    writer = new DataWriter(league);
    try {
        for (int idxSeason = 0; idxSeason < league->getSeasonNum(); idxSeason++) {
            readSeason();
            writePlayer2File(idxSeason + 1);
        }
        reader->closeStream();

    } catch (std::invalid_argument& ia) {

    } catch (std::out_of_range& ofr) {

    }
}

void LeagueManager::readSeason() {
    try {
        SeasonChangeWrapper* seasonChange = reader->readSeasonChange();
        readClub(seasonChange->getClubChange());
        readPlayer(seasonChange->getPlayerChange());
    } catch (std::invalid_argument& ia) {

    } catch (std::out_of_range& ofr) {

    }
}

void LeagueManager::readClub(int clubChangeNum) {
    for (int idxClub = 0; idxClub < clubChangeNum; idxClub++) {
        ClubChangeWrapper* clubChange = reader->readClub();
        ClubRecord aClub(clubChange->getName(), league->getMode());
        switch (clubChange->getMode()) {
        case ADD:
            if (league->getClubManager()->addClub(aClub)) {

                std::cout << "Add successful" << std::endl;
            }
            break;
        case REMOVE:
            if (league->getClubManager()->removeClub(aClub)) {
                std::cout << "Remove successful" << std::endl;
            }
            break;
        default:
            break;
        }
    }
}

void LeagueManager::readPlayer(int playerChangeNum) {
    for (int idxPlayer = 0; idxPlayer < playerChangeNum; idxPlayer++) {
        PlayerChangeWrapper* playerChange = reader->readPlayer();
        ClubRecord aClub(playerChange->getClubName());
        if (league->getClubManager()->isClubExist(aClub)) {
            PlayerRecord aPlayer(playerChange->getPlayerName());
            switch (playerChange->getMode()) {
            case ADD:
                if (league->getClubManager()->getClubJoined(aClub).getPlayerManager()->addPlayer(aPlayer)) {
                    std::cout << "Add successful" << std::endl;
                }
                break;
            case REMOVE:
                if (league->getClubManager()->getClubJoined(aClub).getPlayerManager()->removePlayer(aPlayer)) {
                    std::cout << "Remove successful" << std::endl;
                }
                break;
            default:
                break;
            }
        }
    }
}

void LeagueManager::writeClub2File(std::string path) {
    league->getClubManager()->defragment();
    writer->writeClub2File(path);
}

void LeagueManager::writePlayer2File(int season) {
    std::list<ClubRecord> clubList = league->getClubManager()->getClubsList();
    for (std::list<ClubRecord>::iterator iteClub = clubList.begin(); iteClub != clubList.end(); iteClub++) {
        ClubRecord aClub = *iteClub;
        if (aClub.getPlayerManager() == NULL)
            continue;
        aClub.getPlayerManager()->defragment();
        writer->writePlayer2File(aClub, season);
    }
}

void LeagueManager::writePlayer2File() {
    std::list<ClubRecord> clubList = league->getClubManager()->getClubsList();
    for (std::list<ClubRecord>::iterator iteClub = clubList.begin(); iteClub != clubList.end(); iteClub++) {
        ClubRecord aClub = *iteClub;
        aClub.getPlayerManager()->defragment();
        writer->writePlayer2File(aClub);
    }
}
