#include "Season.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <array>
#include <chrono>

Season::Season( int seasonID, std::vector<Team> teams )
{
    m_seasonID = seasonID;
    m_roundNumber = 1;
    m_leagueTable = teams;
    m_leagueSize = teams.size();

    // Using round robin format where tot. games = n/2 * (n - 1)
    m_totalGames = ( teams.size()/2 ) * ( teams.size() - 1 );

    // Randomises league table based on a random seed and creates fixture matrix.
    initialiseFixtures();
}

void Season::startSeason()
{
    for ( int k = 0; k < (2*m_leagueSize)-2; k++ )
    {
        for ( int i = 0; i < m_leagueSize/2; i++ )
        {
            /**
                Creates game using the one-to-one mapping of home and away
                teams in the round fixtures matrix. Note that the Game
                constructor is taking pointers to Teams within the simulation.
            */
            Game g = Game ( m_roundFixtures[0][i], m_roundFixtures[1][i] );
            g.startGame();
        }
        roundComplete();
    }

    bubbleSortTable();    // Sorts league table only after season complete.
    printLeagueTable();
}

void Season::initialiseFixtures()
{
    // Create a random seed for season.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle( m_leagueTable.begin(), m_leagueTable.end(),
                                         std::default_random_engine(seed) );

    // Creates 2x10 fixtures matrix.
    int n = 0;
    for ( int i = 0; i < 2; i++)
    {
        std::vector<Team *> v;
        for ( int i = 0; i < m_leagueSize / 2; i++ )
        {
            // Adds pointers to teams within the simulation.
            v.push_back( &m_leagueTable[n] );
            n++;
        }
        m_roundFixtures.push_back(v);
    }
}

void Season::roundComplete()
{
    /**
        Checks if simulation is half way through the Season and re-initialises
        the fixtures matrix.
    */
    if ( m_roundNumber == ( m_leagueSize-1 ) )
    {
        initialiseFixtures();
        m_roundNumber++;
        return;
    }

    /**
        Moves each team (except first team) within the fixtures matrix
        clockwise for next round of fixtures to be played.

        Algorithm implementation taken from the wikipedia entry for
        "Round robin tournament".
    */
    for ( int i = 0; i < (m_leagueSize/2)-2; i++ )
    {
        std::iter_swap( &m_roundFixtures[0][1], &m_roundFixtures[0][i+2] );
    }
    for ( int i = (m_leagueSize/2)-1; i >= 0; i-- )
    {
        std::iter_swap( &m_roundFixtures[0][1], &m_roundFixtures[1][i] );
    }

    m_roundNumber++;
}

/**
    Only being used until I can implement a quicksort alternative.

    As mentioned in header file. May god forgive me.
*/
void Season::bubbleSortTable()
{
    for ( int i = 0; i < m_leagueTable.size(); i++ )
    {
        for ( int j = 0; j < m_leagueTable.size(); j++ )
        {
            if ( !m_leagueTable[j].compareTo( m_leagueTable[i] ) )
            {
                std::iter_swap( &m_leagueTable[i], &m_leagueTable[j] );
            }
        }
    }
}

/**
    Prints league table to terminal in the format used by most sports
    broadcasters. Table should be sorted before printing, this is not
    hardcoded for efficiency.
*/
void Season::printLeagueTable()
{
    std::cout << "-----------------------------------------------------------\n";
    printf( "%6s  %-16s %-5s %-5s %-5s %-5s %-5s %-5s\n",
                                                "Pos.",
                                                "Team",
                                                "MP",
                                                "W",
                                                "D",
                                                "L",
                                                "GD",
                                                "Pts." );
    std::cout << "-----------------------------------------------------------\n";
    for ( int i = 0; i < m_leagueTable.size(); i++ )
    {
        printf( "%6d  %-16s %-5d %-5i %-5d %-5d %-5d %-5d\n",
                                   i+1,
                                   m_leagueTable[i].getName().c_str(),
                                   m_leagueTable[i].getTotalGamesPlayed(),
                                   m_leagueTable[i].getTotalWins(),
                                   m_leagueTable[i].getTotalDraws(),
                                   m_leagueTable[i].getTotalLosses(),
                                   m_leagueTable[i].getGoalDifference(),
                                   m_leagueTable[i].getTotalPoints() );
    }
    std::cout << "-----------------------------------------------------------\n";
}

/**
    Prints fixtures taking place in the current round.

    Format: "[homeTeam] vs [awayTeam]"
*/
void Season::printRoundFixtures()
{
    std::cout << "\nRound " << m_roundNumber << " fixtures:\n\n";
    for ( int i = 0; i < (m_leagueTable.size()/2); i++ )
    {
        std::cout << m_roundFixtures[0][i] -> getName()
                  << " vs "
                  << m_roundFixtures[1][i] -> getName()
                  << "\n";
    }
    std::cout << "\n";
}
