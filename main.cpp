#include <iostream>
#include <LeagueManager.h>

using namespace std;

int main()
{
    LeagueManager* league = new LeagueManager();
    league->readData("Input.txt");
    league->writeClub2File("CLUBS.TXT");
}
