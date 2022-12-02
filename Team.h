#ifndef TEAM_
#define TEAM_

#include <iostream>
#include "AVLTree.h"
#include"Player.h"
class Team
{
	shared_ptr<int> teamId;
	int points;
	int totalGoals;
	int totalCards;
	int teamTopScorerId;
	int teamPlayersCount;
	bool hasAGoalKeeper;
	AVLTree<Player> teamPlayersTree;
public:
	Team(int teamId, int points=0, int totalGoals = 0,int totalCards=0, int teamTopScorerId = 0, bool hasAGoalkeeper = false,
		int teamPlayersCount = 0, AVLTree<Player> teamPlayersTree = AVLTree<Player>()) :
		teamId(shared_ptr<int>(&teamId)), points(points),totalGoals(totalGoals), totalCards(totalCards), teamTopScorerId(teamTopScorerId), 
		hasAGoalKeeper(hasAGoalkeeper),teamPlayersCount(teamPlayersCount), teamPlayersTree(teamPlayersTree) {}
	Team(const Team& t) = default;
	~Team() = default;
	Team& operator=(const Team& t);
	shared_ptr<int>& getTeamId();
	friend ostream& operator<<(ostream& os, const Team& t);
	bool operator<(const Team& t1);
	bool operator>(const Team& t1);
};
inline ostream& operator<<(ostream& os, const Team& t)
{
	return os << "Team Id" << *t.teamId;
}
#endif
