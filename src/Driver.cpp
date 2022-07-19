#include "Game.h"
#include "Team.h"
#include "Season.h"
#include "SimulationResults.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
    Forward declarations.
*/
std::vector<Team> parseCSV( std::string fileName );
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
            std::vector<Team> teams = parseCSV("data/season.csv");
            SimulationResults sR = SimulationResults( 10 );

            for ( int i = 0; i < 11; i++ )
            {
                Season s = Season( i, teams );
                s.startSeason();
                sR.addSeason( s );
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

std::vector<Team> parseCSV( std::string fileName )
{
    std::ifstream inputFile;
    inputFile.open( fileName );
    std::string line = "";
    std::vector<Team> teams;

    while ( getline(inputFile, line) )
    {
        std::stringstream inputString(line);
        std::string tempString;
        std::string name;
        double xG;
        double xGA;

        // Parse team name
        getline(inputString, name, ',');

        // Parse xG
        getline(inputString, tempString, ',');
        xG = atof(tempString.c_str());

        // Parse xGA
        getline(inputString, tempString);
        xGA = atof(tempString.c_str());

        // Add to teams vector.
        Team team = Team( name, xG, xGA );
        teams.push_back( team );
        line = "";
    }

    return teams;
}

void printLeague( std::vector<Team> teams )
{
    for ( int i = 0; i < teams.size(); i++ )
    {
        teams[i].toString();
        std::cout << "\n";
    }
}
