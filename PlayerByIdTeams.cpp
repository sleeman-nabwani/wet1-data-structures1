#include "PlayerByIdTeams.h"

bool PlayerByIdTeams::operator<(const PlayerByIdTeams& player1) const{
    if(*this->stats<*player1.stats)
        return true;
    return false;
}
bool PlayerByIdTeams::operator>(const PlayerByIdTeams& player1)const{
    if(player1<*this)
        return true;
    return false;
}