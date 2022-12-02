#include "PlayerById.h"

bool PlayerById::operator<(const PlayerById& player1) const{
    if(this->playerId < player1.playerId){
        return true;
    }
    return false;
}


bool PlayerById::operator>(const PlayerById& player1) const{
    if(*this < player1){
        return false;
    }
    return true;
}
