#include "Season.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <array>
#include <chrono>

Season::Season( int seasonID, std::vector<Team> teams )
{
    m_seasonID = seasonID;
    m_roundNumber = 1;
    m_totalGames = ( teams.size()/2 ) * ( teams.size() - 1 );
    m_leagueTable = teams;
    initialiseFixtures();
}

void Season::initialiseFixtures()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle( m_leagueTable.begin(), m_leagueTable.end(),
                                        std::default_random_engine(seed) );

    int n = 0;
    for ( int i = 0; i < 2; i++)
    {
        std::vector<Team> v;
        for ( int i = 0; i < m_leagueTable.size() / 2; i++ )
        {
            v.push_back( m_leagueTable[n] );
            n++;
        }
        m_roundFixtures.push_back(v);
    }

}

void Season::roundComplete()
{
    int n = m_leagueTable.size();
    if ( m_roundNumber == ( n/2 * (n-1) ) )
    {
        initialiseFixtures();
        m_roundNumber++;
        return;
    }

    for ( int i = 0; i < (n/2)-2; i++ )
    {
        std::iter_swap( &m_roundFixtures[0][1], &m_roundFixtures[0][i+2] );
    }
    for ( int i = (n/2)-1; i >= 0; i-- )
    {
        std::iter_swap( &m_roundFixtures[0][1], &m_roundFixtures[1][i] );
    }

    m_roundNumber++;
}

void Season::printLeagueTable()
{
    for ( int i = 0; i < m_leagueTable.size(); i++ )
    {
        m_leagueTable[i].toString();
        std::cout << "\n";
    }
    std::cout << "* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ *\n";
}

void Season::printRoundFixtures()
{
    std::cout << "\nRound " << m_roundNumber << " fixtures:\n\n";
    for ( int i = 0; i < (m_leagueTable.size()/2); i++ )
    {
        std::cout << m_roundFixtures[0][i].getName()
                  << " vs "
                  << m_roundFixtures[1][i].getName()
                  << "\n";
    }
    std::cout << "\n";
}
