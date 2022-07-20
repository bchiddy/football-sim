/**
    Represents a game between two teams inside the simulation.
    See class diagram in /docs for added context.

    @author:        Ben Chiddy
    @contact:       ben.chiddy@gmail.com
    @since:         19 July 2022
*/

#ifndef GAME_H
#define GAME_H

#include "Team.h"
#include <string>

class Game
{
private:

    Team *m_homeTeam;      // Pointer to team playing at home during this game.
    Team *m_awayTeam;      // Pointer to team playing away during this game.
    int m_homeTeamGoals;   // Amount of goals score by home team.
    int m_awayTeamGoals;   // Amount of goals score by away team.

public:

    /**
        Default constructor and destructor.
    */
    Game() {}
    ~Game() {}

    /**
        Constructor for season simulations where teams are determined in terms
        of home and away. Accepts pointers to teams within the simulation.
    */
    Game( Team *homeTeam, Team *awayTeam );

    /**
        Starts game between two teams within the simulation. The current
        model iteration uses a combination of each teams xG and xGA as
        an estimate for the teams ability to score goals.

        The amount of goals scored by each team is deteremined by a Poisson
        random variable with a weighted average of xG and xGA as it's lambda
        parameter. This is randomly seeded to create varying results for use
        in multiple season simulations.
    */
    void startGame();

    /**
        Methods which log home and away goals. Will also log goals against
        for opposite team.
    */
    void homeGoal( int amount );
    void awayGoal( int amount );

    /**
        Prints score of game to terminal.
    */
    void getScore();

};

#endif
