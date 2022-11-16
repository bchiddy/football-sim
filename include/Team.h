/**
    Represents a season inside the simulation.
    See class diagram in /docs for added context.

    @author:        Ben Chiddy
    @contact:       ben.chiddy@gmail.com
    @since:         19 July 2022
*/

#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <map>

class Team
{
private:

    std::string m_name;         // Team name.
    double m_xG;                // Expected goals.
    double m_xGA;               // Expected goals against.
    int m_totalGoalsFor;        // Total goals scored during season.
    int m_totalGoalsAgainst;    // Total goals scored against during season.
    int m_totalPoints;          // Total points for current season.
    int m_goalDifference;       // Goals for - goals against
    int m_totalWins;            // Total games won.
    int m_totalDraws;           // Total games drawn.
    int m_totalLosses;          // Total games lost.
    int m_totalGamesPlayed;     // Total games played;
    std::map<double, int> m_scoringDistribution;

public:

    /**
        Default constructor and destructor.
    */
    Team() {}
    ~Team() {}

    /**
        Constructor for simulations that only take season
        xG/xGA into account.
    */
    Team( std::string name, double xG, double xGA, std::map<double, int> scoringDistribution );

    /**
        Accessor methods.
    */
    std::string getName() { return m_name; }
    double get_xG() { return m_xG; }
    double get_xGA() { return m_xGA; }
    int getTotalGoalsfor() { return m_totalGoalsFor; }
    int getTotalGoalsAgainst() { return m_totalGoalsAgainst; }
    int getTotalPoints() { return m_totalPoints; }
    int getGoalDifference() { return m_goalDifference; }
    int getTotalWins() { return m_totalWins; }
    int getTotalLosses() { return m_totalLosses; }
    int getTotalDraws() { return m_totalDraws; }
    int getTotalGamesPlayed() { return m_totalGamesPlayed; }

    /**
        Mutator methods.
    */
    void set_xG( double xG ) { m_xG = xG; }
    void set_xGA( double xGA ) { m_xGA = xGA; }
    void incrementPoints( int amount ) { m_totalPoints += amount; }

    /**
        Methods for incrementing overall goals for and against.
        Used during the lifetime of a game.
    */
    void goalScored( int amount );
    void goalAgainstScored( int amount );

    /**
        Methods for logging wins, draws and losses. Will also update
        total points for this team based on results.
    */
    void logWin();
    void logDraw();
    void logLoss();

    /**
        Method which compares this -> team to another team.

        Returns true if this -> team has higher total points.
        If this -> team has equal points returns true if this -> team
        has a higher goal difference.

        Used when sorted league table.
    */
    bool compareTo( Team t );

    /**
        Prints team name and statistics.

        Format: "Team name: [teamName]"
                "xG:         [xG]"
                "xGA:        [xGA]"
    */
    void toString();
};

#endif
