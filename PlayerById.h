#ifndef MAIN23A1_CPP_PLAYERBYID_H
#define MAIN23A1_CPP_PLAYERBYID_H
#include "Player.h"
#include <iostream>
using namespace std;

class PlayerById {
    int playerId;
    Player* stats;

public:
    /// C'tor
    PlayerById(int playerId, Player* stats = nullptr): playerId(playerId), stats(stats) {}
    /// Copy C'tor
    PlayerById(const PlayerById& player) = default;
    /// destructor
    ~PlayerById() = default;
    /// overloaded operators
    PlayerById& operator=(const PlayerById& p) = default;
    friend ostream& operator<<(ostream& os, const PlayerById& p);
    bool operator<(const PlayerById& player1) const;
    bool operator>(const PlayerById& player1) const;
};

inline ostream& operator<<(ostream& os, const PlayerById& p)
{
    return os << *(p.stats);
}

#endif //MAIN23A1_CPP_PLAYERBYID_H
