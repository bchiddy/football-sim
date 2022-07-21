#include "../include/IODriver.h"
#include "../include/Team.h"
#include <vector>
#include <fstream>
#include <sstream>

IODriver::IODriver( std::string inputFileName,
                    std::string outputFileName, int numberOfSeasons )
{
    m_inputFileName = inputFileName;
    m_outputFileName = outputFileName;
    m_numberOfSeasons = numberOfSeasons;
}

std::vector<Team> IODriver::parseCSV( )
{
    std::ifstream inputFile;
    inputFile.open( m_inputFileName );
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

    inputFile.close();

    createPositionMap( teams );
    createCSVHeader();
    return teams;
}

void IODriver::createPositionMap( std::vector<Team> teams )
{
    for ( int i = 0; i < teams.size(); i++ )
    {
        m_positionMap.insert( std::pair<std::string, int>(teams[i].getName(),i));
    }
}

void IODriver::createCSVHeader()
{
    std::ofstream outputFile( m_outputFileName );

    std::map<std::string, int>::iterator it;
    for (it = m_positionMap.begin(); it != m_positionMap.end(); it++)
    {
        outputFile << it->first << ",";
    }
    outputFile << "\n";

    outputFile.close();
}

void IODriver::writeResultToCSV( std::vector<Team> leaguePositions )
{
    std::ofstream outputFile( m_outputFileName, std::ios::app );

    // Map positions for the current sim run.
    for ( int i = 0; i < leaguePositions.size(); i++ )
    {
        std::map<std::string, int>::iterator it =
                        m_positionMap.find( leaguePositions[i].getName() );
        if ( it != m_positionMap.end() )
        {
            it->second = i+1;
        }
    }

    // Write these positions to results csv in alphabetical order.
    std::map<std::string, int>::iterator it;
    for (it = m_positionMap.begin(); it != m_positionMap.end(); it++)
    {
        outputFile << it->second << ",";
    }

    outputFile << "\n";
    outputFile.close();
}
