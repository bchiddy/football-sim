#include "../include/Game.h"
#include "../include/Team.h"
#include "../include/Season.h"
#include "../include/IODriver.h"
#include <iostream>

/**
    Forward delarations.
*/
void printLeague( std::vector<Team> teams );

int main()
{
    std::cout << "\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
    std::cout << "* Welcome to the Premier League simulator! *\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";

    IODriver io = IODriver( "data/season.csv", "data/results.csv" );
    std::vector<Team> teams = io.parseCSV();

    std::string selection;

    do
    {
        std::cout << "\n";
        std::cout << "Please select: \n";
        std::cout << "[1] Simulate a single season.\n";
        std::cout << "[2] Simulate multiple seasons.\n";
        std::cout << "[3] Exit simulator.\n";
        std::cout << "\n";
        std::cout << "Enter selection: ";
        std::cin >> selection;
        std::cout << "\n";

        if ( selection.compare("1") == 0 )
        {
            Season s = Season( 1, teams );
            s.startSeason();
            s.printLeagueTable();
        }
        else if ( selection.compare("2") == 0 )
        {
            std::cout << "Starting simulation . . .\n";
            for ( int i = 0; i < 500; i++ )
            {
                Season s = Season( i, teams );
                s.startSeason();
                io.writeResultToCSV( s.getLeagueTable() );
            }
            std::cout << "Simulation complete! See /docs/results.csv for results.\n";
        }
        else
        {
            std::cout << "Please select either [1],[2], or [3] \n";
        }

    } while ( selection.compare("3") != 0 );

    std::cout << "\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
    std::cout << "* Thanks for using the Premier League simulator. Goodbye. *\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
    std::cout << "\n";

    return 0;
}

void printLeague( std::vector<Team> teams )
{
    for ( int i = 0; i < teams.size(); i++ )
    {
        teams[i].toString();
        std::cout << "\n";
    }
}
