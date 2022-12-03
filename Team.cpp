#include "Team.h"


    Team::Team(int teamId, int points, int teamTopScorerId,
     bool hasGoalKeeper, int teamPlayersCount,
     int totalGoals, int totalCards, AVLTree<Player> teamPlayersTree):
        points(points), teamTopScorerId(teamTopScorerId), hasGoalKeeper(hasGoalKeeper),
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


shared_ptr<int>& Team::getTeamId()
{
    return teamId;
}

int Team::getTeamPlayersCount() const {
    return teamPlayersCount;
}

int Team::getTotalCards() const {
    return totalCards;
}

int Team::getTotalGoals() const {
    return totalGoals;
}

bool Team::hasKeeper() const {
    return hasGoalKeeper;
}

int Team::getPoints() const {
    return points;
}

void Team::updatePoints(int x) {
    points += x;
}


int Team::getTopScorer() const {
    return teamTopScorerId;
}




