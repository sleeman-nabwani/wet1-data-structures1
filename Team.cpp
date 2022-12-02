#include "Team.h"


    Team::Team(int teamId, int points, int teamTopScorerId,
     bool hasAGoalkeeper, int teamPlayersCount,
     int totalGoals, int totalCards, AVLTree<Player> teamPlayersTree):
        points(points), teamTopScorerId(teamTopScorerId), hasAGoalKeeper(hasAGoalkeeper),
        teamPlayersCount(teamPlayersCount), totalGoals(totalGoals),
        totalCards(totalCards), teamPlayersTree(teamPlayersTree) {
    this->teamId = make_shared<int>(teamId);
}


    Team& Team::operator=(const Team& t)
{
	teamId = t.teamId;
	points = t.points;
	teamTopScorerId = t.teamTopScorerId;
	teamPlayersCount = t.teamPlayersCount;
    totalCards = t.totalCards;
    totalGoals = t.totalGoals;
	teamPlayersTree = t.teamPlayersTree;
	return *this;
}

shared_ptr<int>& Team::getTeamId()
{
	return teamId;
}

bool Team::operator<(const Team& t1)
{
	if (*this->teamId < *t1.teamId)
		return true;
	return false;
}
bool Team::operator>(const Team& t1)
{
	if (*this->teamId > *t1.teamId)
		return true;
	return false;
}
