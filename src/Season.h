/**
    Represents a season inside the simulation.
    See class diagram in /docs for added context.

    @author:        Ben Chiddy
    @contact:       ben.chiddy@gmail.com
    @since:         08 July 2022
*/

#ifndef SEASON_H
#define SEASON_H

#include "Team.h"
#include "Game.h"
#include <string>
#include <vector>
#include <map>

class Season
{
private:

    int m_seasonID;
    int m_totalGames;
    int m_roundNumber;
    std::vector<Team> m_leagueTable;
    std::vector< std::vector<Team> > m_roundFixtures;

public:

    /**
        Default constructor and Destructor.
    */
    Season() {}
    ~Season() {}

    // Constructor used in simulation.
    Season( int seasonID, std::vector<Team> teams );

    // Accessor methods.
    int getSeasonID() { return m_seasonID; }
    std::vector<Team> getLeagueTable() { return m_leagueTable; };
    std::vector< std::vector<Team> >  getFixtures() { return m_roundFixtures; };

    void initialiseFixtures();
    void roundComplete();
    void printLeagueTable();
    void printRoundFixtures();
    void updateLeagueTable( );
    int partition( std::vector<Team> arr, int low, int high );
    void quickSort( std::vector<Team> arr, int low, int high);
    void startSeason();

};

#endif
