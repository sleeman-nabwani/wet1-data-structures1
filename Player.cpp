#include "Player.h"

/*Player::Player(const Player& p)
{
	playerId = p.playerId;
	teamId = p.teamId;
	isGoalKeeper = p.isGoalKeeper;
	gamesPlayed = p.gamesPlayed;
	goals = p.goals;
	cards = p.cards;
}

Player& Player::operator=(const Player& p){
	playerId = p.playerId;
	teamId = p.teamId;
	isGoalKeeper = p.isGoalKeeper;
	gamesPlayed = p.gamesPlayed;
	goals = p.goals;
	cards = p.cards;
	return *this;
}*/

bool Player::operator<(const Player& p1) const{
	if (p1.goals > this->goals)
		return true;
	if (p1.goals == this->goals) {
		if (p1.cards < this->cards)
			return true;
		if (p1.cards == this->cards) {
			if (p1.playerId > this->playerId)
				return true;
		}
	}
	return false;
}
bool Player::operator>(const Player& p1) const{
	if (*this < p1)
		return false;
	return true;
}

Player::Player(int playerId, shared_ptr<int> teamId, bool GoalKeeper, int gamesPlayed, int goals, int cards):
        playerId(playerId), isGoalKeeper(GoalKeeper), gamesPlayed(gamesPlayed), goals(goals), cards(cards) {
    this->teamId = teamId;
}


