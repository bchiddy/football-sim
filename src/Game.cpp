#include "Game.h"
#include "Team.h"
#include <iostream>

Game::Game( Team homeTeam, Team awayTeam )
{
    m_homeTeam = homeTeam;
    m_awayTeam = awayTeam;
    m_homeTeamGoals = 0;
    m_awayTeamGoals = 0;
}

void Game::homeGoal()
{
    m_homeTeamGoals++;
    m_homeTeam.goalScored();
    m_awayTeam.goalAgainstScored();
}

void Game::awayGoal()
{
    m_awayTeamGoals++;
    m_awayTeam.goalScored();
    m_homeTeam.goalAgainstScored();
}

void Game::getScore()
{
    std::cout << m_homeTeam.getName() << " "
              << m_homeTeamGoals << " - "
              << m_awayTeamGoals << " "
              << m_awayTeam.getName() << "\n";
}
