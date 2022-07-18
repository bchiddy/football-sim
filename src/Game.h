/**
    Represents a game between two teams inside the simulation.
    See class diagram in /docs for added context.

    @author:        Ben Chiddy
    @contact:       ben.chiddy@gmail.com
    @since:         08 July 2022
*/

#ifndef GAME_H
#define GAME_H

#include "Team.h"
#include <string>

class Game
{
private:

    Team m_homeTeam;        // Team playing at home during this game.
    Team m_awayTeam;        // Team playing away during this game.
    int m_homeTeamGoals;    // Goals score by home team.
    int m_awayTeamGoals;    // Goals score by away team.

public:

    /**
        Default constructor and Destructor.
    */
    Game() {}
    ~Game() {}

    /**
        Constructor for simulations where teams are determined in terms
        of home and away.
    */
    Game( Team homeTeam, Team awayTeam );

    /**
        Methods which log home and away goals. Will also log goals against
        for opposite team.
    */
    void startGame();
    void homeGoal( int amount );
    void awayGoal( int amount );

    /**
        Prints score of game. See .cpp file for format.
    */
    void getScore();

};

#endif
