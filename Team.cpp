#include "Team.h"

Team& Team::operator=(const Team& t)
{
	teamId = t.teamId;
	points = t.points;
	teamTopScorerId = t.teamTopScorerId;
	teamPlayersCount = t.teamPlayersCount;
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
