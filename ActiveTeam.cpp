#include "ActiveTeam.h"

ActiveTeam::ActiveTeam(Team& team){
    stats= make_shared<Team>(team);
}

bool ActiveTeam::operator<(const ActiveTeam& team) const{
    if(*this->stats < *team.stats){
        return true;
    }
    return false;
}
bool ActiveTeam::operator>(const ActiveTeam& team)const{
    return *team.stats<*this->stats;
}