#ifndef MAIN23A1_CPP_PLAYERBYIDTEAMS_H
#define MAIN23A1_CPP_PLAYERBYIDTEAMS_H
#include "PlayerById.h"

class PlayerByIdTeams: public PlayerById {
public:
    PlayerByIdTeams(Player& player): PlayerById(player){}
    bool operator<(const PlayerByIdTeams& player1) const;
    bool operator>(const PlayerByIdTeams& player1) const;
};

#endif //MAIN23A1_CPP_PLAYERBYIDTEAMS_H
