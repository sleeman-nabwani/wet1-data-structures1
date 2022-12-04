#include "Team.h"


    Team::Team(int teamId, int points, int teamTopScorerId,
     bool hasGoalKeeper,int totalTeamGames, int teamPlayersCount,
     int totalGoals, int totalCards, AVLTree<Player> teamPlayersTree):
        points(points), teamTopScorerId(teamTopScorerId), hasGoalKeeper(hasGoalKeeper),
        teamPlayersCount(teamPlayersCount), totalGoals(totalGoals),
        totalCards(totalCards), teamPlayersTree(teamPlayersTree) {
    this->totalTeamGames= make_shared<int>(totalTeamGames);
    this->teamId = make_shared<int>(teamId);
}


    Team& Team::operator=(const Team& t)
{
	teamId = t.teamId;
	points = t.points;
	teamTopScorerId = t.teamTopScorerId;
	teamPlayersCount = t.teamPlayersCount;
    totalCards = t.totalCards;
    totalTeamGames=t.totalTeamGames;
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

void Team::teamPlayersInOrder(Player *playersArray) {
    teamPlayersTree.inorder(playersArray);
}

void Team::updateGamesPlayed() {
    (*totalTeamGames)++;
}

void Team::moveTeam(Team &team){
    this->points += team.points;
    this->teamPlayersCount += team.teamPlayersCount;
    this->totalGoals += team.totalGoals;
    this->totalCards += team.totalCards;
    /// Update top scorer
    Player teamOneTopScorer = *this->teamPlayersTree.getMax()->data;
    Player teamTwoTopScorer = *team.teamPlayersTree.getMax()->data;
    if(teamOneTopScorer < teamTwoTopScorer)
        this->teamTopScorerId = teamTwoTopScorer.getId();
    else
        this->teamTopScorerId = teamOneTopScorer.getId();
    /// Update goalkeeper
    if(this->hasGoalKeeper || team.hasGoalKeeper)
        this->hasGoalKeeper = true;
    /// seggs tmrw



    *totalTeamGames = 0;


}




