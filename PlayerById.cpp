#include "PlayerById.h"
PlayerById::PlayerById(Player &player):playerId(player.getId()) {
    stats= make_shared<Player>(player);
}

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
