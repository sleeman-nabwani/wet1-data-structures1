//
// Created by Rund on 12/3/2022.
//

#ifndef MAIN23A1_CPP_ACTIVETEAM_H
#define MAIN23A1_CPP_ACTIVETEAM_H

#include "Team.h"

class ActiveTeam
{
    shared_ptr<Team> stats;
public:
    explicit ActiveTeam(Team& team);
    ActiveTeam(const ActiveTeam& team)=default;
    ~ActiveTeam()=default;
    ActiveTeam& operator=(const ActiveTeam& team)=default;
    friend ostream& operator<<(ostream& os, const ActiveTeam& t);
    bool operator<(const ActiveTeam& team) const;
    bool operator>(const ActiveTeam& team) const;
};
inline ostream& operator<<(ostream& os, const ActiveTeam& t)
{
    return os << *(t.stats);
}
#endif //MAIN23A1_CPP_ACTIVETEAM_H
