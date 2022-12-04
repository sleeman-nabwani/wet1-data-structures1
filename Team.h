#ifndef TEAM_
#define TEAM_

#include <iostream>
#include "AVLTree.h"
#include"Player.h"
class Team
{
	shared_ptr<int> teamId;
	int points;
	int teamTopScorerId;
	int teamPlayersCount;
	bool hasGoalKeeper;
    shared_ptr<int> totalTeamGames;
    int totalGoals;
    int totalCards;
	AVLTree<Player> teamPlayersTree;
public:
    /// C'tor:
	Team(int teamId, int points = 0, int teamTopScorerId = 0,
         bool hasGoalKeeper = false,int totalTeamGames = 0, int teamPlayersCount = 0,
         int totalGoals = 0, int totalCards = 0, AVLTree<Player> teamPlayersTree = AVLTree<Player>());
    /// Copy C'tor:
	Team(const Team& t) = default;
    /// destructor:
	~Team() = default;
    /// overloaded operators:
	Team& operator=(const Team& t);
	friend ostream& operator<<(ostream& os, const Team& t);
	bool operator<(const Team& t1);
	bool operator>(const Team& t1);
    /// getters:
    shared_ptr<int>& getTeamId();
    int getTeamPlayersCount() const;
    int getTotalCards() const;
    int getTotalGoals() const;
    bool hasKeeper() const;
    int getPoints() const;
    int getTopScorer() const;
    /// setters & such:
    void updatePoints(int x);
    void updateGamesPlayed();
    /// functions:
    void teamPlayersInOrder(Player* playersArray);
    void moveTeam(Team &team);

};
inline ostream& operator<<(ostream& os, const Team& t)
{
	return os << "Team Id" << *t.teamId;
}
#endif
