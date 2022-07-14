#include "Team.h"
#include <iostream>

Team::Team( std::string name, double xG, double xGA )
{
    m_name = name;
    m_xG = xG;
    m_xGA = xGA;
    m_totalGoalsFor = 0;
    m_totalGoalsAgainst = 0;
}

void Team::toString()
{
    std::cout << "Team name:     " << m_name << "\n"
              << "xG:            " << m_xG << "\n"
              << "xGA:           " << m_xGA << "\n";
}
