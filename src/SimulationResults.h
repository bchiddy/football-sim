#ifndef SIMULATIONRESULTS_H
#define SIMULATIONRESULTS_H

class SimulationResults
{
private:

    std::vector<Season> m_seasonResults;
    int m_nextPosition;

public:

    SimulationResults();
    ~SimulationResults();

    SimulationResults( int numberOfSeasons )
    {
        m_nextPosition = 0;
    }

    void addSeason( Season s )
    {
        m_seasonResults.push_back( s );
    }

};

#endif
