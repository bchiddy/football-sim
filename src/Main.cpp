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
    std::string proceed;

    std::cout << "\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
    std::cout << "Welcome to the Premier League simulator!\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
    std::cout << "Would you like to start? [Y/N]: ";
    std::cin >> proceed;
    std::cout << "\n";

    // Read and run simulation
    do
    {
        if ( proceed.compare("Y") == 0 )
        {
            IODriver io = IODriver( "data/season.csv", "data/results.csv", 5 );
            std::vector<Team> teams = io.parseCSV();

            for ( int i = 0; i < 500; i++ )
            {
                Season s = Season( i, teams );
                s.startSeason();
                io.writeResultToCSV( s.getLeagueTable() );
            }

        }
        else if ( proceed.compare("N") == 0 )
        {
            std::cout << "Ok. Goodbye\n";
        }

        std::cout << "Would you like to run the simulation again? [Y/N]: ";
        std::cin >> proceed;
        std::cout << "\n";

    } while ( proceed.compare("Y") == 0 );

    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
    std::cout << "Thanks for using the Premier League simulator. Goodbye.\n";
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";

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
