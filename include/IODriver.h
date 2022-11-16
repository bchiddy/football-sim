#ifndef IODRIVER_H
#define IODRIVER_H

#include "../include/Team.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class IODriver
{
private:

    std::string m_inputFileName;
    std::string m_outputFileName;
    std::map<std::string, int> m_positionMap;

public:

    IODriver() {}
    ~IODriver() {}

    IODriver( std::string inputFileName, std::string outputFileName );

    void createPositionMap( std::vector<Team> teams );
    std::vector<Team> parseCSV();
    std::map<double, int> createScoringDistribution( std::string teamName );
    void createCSVHeader();
    void writeResultToCSV( std::vector<Team> leaguePositions );

};

#endif
