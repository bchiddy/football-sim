/**
    Represents a season inside the simulation.
    See class diagram in /docs for added context.

    @author:        Ben Chiddy
    @contact:       ben.chiddy@gmail.com
    @since:         19 July 2022
*/

#ifndef SEASON_H
#define SEASON_H

#include "Team.h"
#include "Game.h"
#include <string>
#include <vector>

class Season
{
private:

    int m_seasonID;                     // ID of current season in simulation.
    int m_roundNumber;                  // Round number within current season.
    int m_leagueSize;                   // Amount of teams inside the simulation.
    int m_totalGames;                   // Total games created during this sim.
    std::vector<Team> m_leagueTable;    // Ordered using points and goal diff.

    /**
        2x10 matrix of pointers where the first row represents home teams and
        the second row represents away teams. During each round, home teams
        play against away teams with a one-to-one mapping.
    */
    std::vector< std::vector<Team *> > m_roundFixtures;

public:

    /**
        Default constructor and destructor.
    */
    Season() {}
    ~Season() {}

    /**
        Constructor used in multiple seasons simulation. Accepts a season ID
        number for use in analysis and an unordered vector of Team objects.

        Constructor will set member variables and randomise the order of
        the Teams vector for each Season. This is to ensure a random order
        of games within each Season.
    */
    Season( int seasonID, std::vector<Team> teams );

    /**
        Accessor methdods for member variables.
    */
    int getSeasonID() { return m_seasonID; }
    std::vector<Team> getLeagueTable() { return m_leagueTable; };
    std::vector< std::vector<Team *> >  getFixtures() { return m_roundFixtures; };

    void startSeason();

    /**
        Randomises order of league table and instatiates round fixtures matrix.
    */
    void initialiseFixtures();

    /**
        Increments round number and updates the round fixtures matrix for the
        next round of fixtures to be played in the season.

        Uses the round robin algorithm to schedule fixtures where every team
        plays each both home and away. This is achieved through shifting every
        team within the matrix (except the first team) clockwise.
    */
    void roundComplete();

    /**
        Orders the league table on firstly the amount of points each team has
        and then on their goal difference (goals for - goals against).

        Terribly inefficient, and only being used until I can solve
        how to implement quicksort using references/ pointers.

        May god forgive me for using this algorithm.
    */
    void bubbleSortTable();

    /**
        Prints league table in a format similar to TV graphics during games.
    */
    void printLeagueTable();

    /**
        Prints rounds to be played during the current round.
    */
    void printRoundFixtures();

};

#endif
