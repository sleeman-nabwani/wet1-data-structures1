#ifndef PLAYER_
#define PLAYER_
#include <iostream>
#include <memory>
using namespace std;
class Player
{
	int playerId;
	shared_ptr<int> teamId;
	bool isGoalKeeper;
    int teamGamesWhenJoind;
    shared_ptr<int> teamGamesPlayed;
	int gamesPlayed;
	int goals;
	int cards;

public:
    /// dummy C'tor
    Player() {}
    /// C'tor
	Player(int playerId, shared_ptr<int> teamId = nullptr, bool GoalKeeper=false,int teamGamesWhenJoind=0,shared_ptr<int> teamGamesPlayed= nullptr ,int gamesPlayed = 0, int goals = 0, int cards = 0);
    /// Copy C'tor
    Player(const Player& p) = default;
    /// destructor
	~Player() = default;
    /// overloaded operators
	Player& operator=(const Player& p) = default;
    const int getId() const;
	friend ostream& operator<<(ostream& os, const Player& p);
	bool operator<(const Player& p1) const;
	bool operator>(const Player& p1) const;
    /// getters
    int getGamesPlayed() const;
};
inline ostream& operator<<(ostream& os, const Player& p) {
    return os << "Player Id : " << p.playerId << " Team Id : " << *p.teamId;
}

#endif
