#include "../include/Game.h"
#include "../include/Team.h"
#include "../include/Season.h"
#include "../include/IODriver.h"
#include <chrono>
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
    int numberOfSeasons = 1;

    do
    {
        system("clear");
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
            system("clear");
            Season s = Season( 1, teams );
            s.startSeason();
            s.printLeagueTable();
        }
        else if ( selection.compare("2") == 0 )
        {
            system("clear");
            std::cout << "Enter many seasons would you like to simulate: ";
            std::cin >> numberOfSeasons;

            auto start = std::chrono::high_resolution_clock::now();
            std::cout << "Starting simulation . . .\n";
            for ( int i = 0; i < numberOfSeasons; i++ )
            {
                Season s = Season( i, teams );
                s.startSeason();
                io.writeResultToCSV( s.getLeagueTable() );
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Simulation complete! See /docs/results.csv for results.\n\n";
            std::cout << "Time taken to run " << numberOfSeasons
                                              << " seasons: "
                                              << duration.count() / 1000
                                              << " miliseconds.\n\n";
            std::cout << "See /docs/results.csv for results.\n";
        }
        else
        {
            system("clear");
            std::cout << "Please select either [1],[2], or [3] \n";
        }

    } while ( selection.compare("3") != 0 );

    system("clear");
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
