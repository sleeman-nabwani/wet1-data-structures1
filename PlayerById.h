#ifndef MAIN23A1_CPP_PLAYERBYID_H
#define MAIN23A1_CPP_PLAYERBYID_H
#include "Player.h"
#include <iostream>
using namespace std;

class PlayerById {
protected:
    int playerId;
    shared_ptr<Player> stats;

public:
    /// C'tor
    PlayerById(Player& player);
    /// Copy C'tor
    PlayerById(const PlayerById& player) = default;
    /// destructor
    virtual ~PlayerById() = default;
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
