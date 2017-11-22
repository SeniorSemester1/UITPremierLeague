#include <iostream>
#include <LeagueManager.h>

using namespace std;

int main()
{
    LeagueManager* league = new LeagueManager("Input.txt");
    league->readData();
}
