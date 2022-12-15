#include "../include/IODriver.h"
#include "../include/Team.h"
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

IODriver::IODriver( std::string inputFileName, std::string outputFileName )
{
    m_inputFileName = inputFileName;
    m_outputFileName = outputFileName;
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

        // Create goal scoring distubtion for team
        std::map<double, int> scoringDistribution = createScoringDistribution( name );
        
        // Add to teams vector.
        Team team = Team( name, xG, xGA, scoringDistribution);
        teams.push_back( team );
        line = "";
    }

    inputFile.close();

    createPositionMap( teams );
    createCSVHeader();
    return teams;
}

// new code for parsing goals scored into a team distribution for scorring
std::map<double, int> IODriver::createScoringDistribution( std::string teamName )
{
    std::ifstream inputFile;
    inputFile.open( "data/2022/" + teamName + ".csv");
    std::string line = "";
    std::vector<int> goals;
    std::map<double, int> scoringDistribution; 

    // Parse historic goals scored
    while ( getline(inputFile, line) )
    {
        std::stringstream inputString(line);
        std::string tempString;
        std::string name;

        // Record goal
        getline(inputString, tempString);
        goals.push_back( atoi(tempString.c_str()) );
        line = "";
    }
    sort( goals.begin(), goals.end() );
    inputFile.close();

    // Create Distribution
    double proportion = 0;
    int position = 0;
    // std::cout << teamName << "\n";
    for ( int i=0; i < goals[goals.size()-1]; i++)
    {
        int count = 0;
        while ( goals[position] == i)
        {
            count++;
            position++;
        }

        proportion = proportion + (double) count / goals.size();
        scoringDistribution.insert( {proportion, i} );
    }

    return scoringDistribution;
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

