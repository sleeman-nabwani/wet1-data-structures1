#ifndef PLAYER_
#define PLAYER_
#include <iostream>
using namespace std;
class Player
{
	int playerId;
	shared_ptr<int> teamId;
	bool isGoalKeeper;
	int gamesPlayed;
	int goals;
	int cards;
public:
	Player(int playerId, shared_ptr<int> teamId, bool GoalKeeper=false, int gamesPlayed = 0, int goals = 0, int cards = 0) :playerId(playerId),
		teamId(teamId), isGoalKeeper(GoalKeeper), gamesPlayed(gamesPlayed), goals(goals), cards(cards) {}
	Player(const Player& p);
	~Player()=default;
	Player& operator=(const Player& p);
	friend ostream& operator<<(ostream& os, const Player& p);
	bool operator<(const Player& p1);
	bool operator>(const Player& p1);
};
inline ostream& operator<<(ostream& os, const Player& p)
{
	return os << "Player Id : " << p.playerId <<"    Team Id : "<<*p.teamId;
}
#endif
