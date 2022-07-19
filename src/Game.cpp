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
    m_homeTeamGoals += amount;
    m_homeTeam -> goalScored( m_homeTeamGoals );
    m_awayTeam -> goalAgainstScored( m_awayTeamGoals );
}

void Game::awayGoal( int amount )
{
    m_awayTeamGoals += amount;
    m_awayTeam -> goalScored( m_awayTeamGoals );
    m_homeTeam -> goalAgainstScored( m_homeTeamGoals );
}

void Game::startGame()
{
    // Create a random seed for game.
    unsigned s = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator;
    generator.seed( s );

    // Create Poisson RV representing goals scored by home team.
    std::poisson_distribution <int>
                home_xG( (m_homeTeam -> get_xG() * 0.6)
                + (m_awayTeam -> get_xGA() * 0.4) / 2 );

    // Create Poisson RV representing goals scored by away team.
    std::poisson_distribution <int>
                away_xG( (m_awayTeam -> get_xG() * 0.4)
                + (m_homeTeam -> get_xGA() * 0.6) / 2 );

    int homeGoals = home_xG( generator ); // Total home goals for game.
    int awayGoals = away_xG( generator ); // Total home goals for game.

    homeGoal( homeGoals ); // Logs goals for home team.
    awayGoal( awayGoals ); // Logs goals for away team.

    /**
        Increments points for each team based on the result.

        Win = 3 point for winning team (most goals)
        Draw = 1 point for both teams
    */
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
    std::cout << m_homeTeam -> getName() << " "
              << m_homeTeamGoals << " - "
              << m_awayTeamGoals << " "
              << m_awayTeam -> getName() << "\n";
}
