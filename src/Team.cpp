#include "Team.h"
#include <iostream>

Team::Team( std::string name, double xG, double xGA )
{
    m_name = name;
    m_xG = xG;
    m_xGA = xGA;
    m_totalGoalsFor = 0;
    m_totalGoalsAgainst = 0;
    m_totalPoints = 0;
    m_goalDifference = 0;
}

void Team::goalScored( int amount )
{
    m_totalGoalsFor += amount;
    m_goalDifference = m_totalGoalsFor - m_totalGoalsAgainst;
}

void Team::goalAgainstScored( int amount )
{
    m_totalGoalsAgainst += amount;
    m_goalDifference = m_totalGoalsFor - m_totalGoalsAgainst;

}

bool Team::compareTo( Team t )
{
    if ( m_totalPoints > t.getTotalPoints() )
    {
        return true;
    }
    else if ( m_totalPoints < t.getTotalPoints() )
    {
        return false;
    }
    else
    {
        if ( m_goalDifference > t.getGoalDifference() )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Team::toString()
{
    std::cout << "Team name:     " << m_name << "\n"
              << "xG:            " << m_xG << "\n"
              << "xGA:           " << m_xGA << "\n";
}
