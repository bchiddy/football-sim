/**
    Represents a season inside the simulation.
    See class diagram in /docs for added context.

    @author:        Ben Chiddy
    @contact:       ben.chiddy@gmail.com
    @since:         08 July 2022
*/

#ifndef TEAM_H
#define TEAM_H

#include <string>

class Team
{
private:

    std::string m_name;         // Team name.
    double m_xG;                // Expected goals.
    double m_xGA;               // Expected goals against.
    int m_totalGoalsFor;        // Total goals scored during season.
    int m_totalGoalsAgainst;    // Total goals scored against during season.
    int m_totalPoints;          // Total points for current season.

public:

    /**
        Default constructor and Destructor.
    */
    Team() {}
    ~Team() {}

    /**
        Constructor for simulations that only take season
        xG/xGA into account.
    */
    Team( std::string name, double xG, double xGA );

    /**
        Accessor methods.
    */
    std::string getName() { return m_name; }
    void set_xG( double xG ) { m_xG = xG; }
    void set_xGA( double xGA ) { m_xGA = xGA; }
    double get_xG() { return m_xG; }
    double get_xGA() { return m_xGA; }
    int getTotalGoalsfor() { return m_totalGoalsFor; }
    int getTotalGoalsAgainst() { return m_totalGoalsAgainst; }
    int getTotalPoints() { return m_totalPoints; }

    /**
        Methods for incrementing overall goals for and against.
        Used during game time.
    */
    void goalScored() { m_totalGoalsFor++; }
    void goalAgainstScored() { m_totalGoalsAgainst++; }

    /**
        Prints team name and statistics. See .cpp file for format.
    */
    void toString();
};

#endif
