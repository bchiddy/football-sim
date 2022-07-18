#include "Game.h"
#include "Team.h"
#include <iostream>
#include <random>

Game::Game( Team *homeTeam, Team *awayTeam )
{
    m_homeTeam = homeTeam;
    m_awayTeam = awayTeam;
    m_homeTeamGoals = 0;
    m_awayTeamGoals = 0;
}

void Game::homeGoal( int amount )
{
    /**
        For usage in "live" game setting.

        m_homeTeamGoals++;
        m_homeTeam.goalScored();
        m_awayTeam.goalAgainstScored();
    */

    m_homeTeamGoals += amount;
    m_homeTeam -> goalScored( m_homeTeamGoals );
    m_awayTeam -> goalAgainstScored( m_awayTeamGoals );
}

void Game::awayGoal( int amount )
{

    /**
        For usage in "live" game setting.

        m_awayTeamGoals++;
        m_awayTeam.goalScored();
        m_homeTeam.goalAgainstScored();
    */

    m_awayTeamGoals += amount;
    m_awayTeam -> goalScored( m_awayTeamGoals );
    m_homeTeam -> goalAgainstScored( m_homeTeamGoals );
}

void Game::startGame()
{
    unsigned s = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator;
    generator.seed( s );

    std::poisson_distribution <int>
                home_xG( (m_homeTeam -> get_xG()*0.6) + (m_awayTeam -> get_xGA()*0.4) / 2 );
    std::poisson_distribution <int>
                away_xG( (m_awayTeam -> get_xG()*0.6) + (m_homeTeam -> get_xGA()*0.4) / 2 );

    int homeGoals = home_xG( generator );
    int awayGoals = away_xG( generator );

    homeGoal( homeGoals );
    awayGoal( awayGoals );

    if ( m_homeTeamGoals > m_awayTeamGoals )
    {
        m_homeTeam -> incrementPoints( 3 );
    }
    else if ( m_awayTeamGoals > m_homeTeamGoals )
    {
        m_awayTeam -> incrementPoints( 3 );
    }
    else
    {
        m_homeTeam -> incrementPoints( 1 );
        m_awayTeam -> incrementPoints( 1 );
    }
}

void Game::getScore()
{
    std::cout << m_homeTeam ->getName() << " "
              << m_homeTeamGoals << " - "
              << m_awayTeamGoals << " "
              << m_awayTeam -> getName() << "\n";
}
