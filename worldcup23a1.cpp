#include "worldcup23a1.h"
#define TEAM_WIN 3
#define TEAM_DRAW 1


int calculateScore(Team team){
    return team.getPoints() + team.getTotalGoals() - team.getTotalCards();
}


world_cup_t::world_cup_t(): allPlayersCount(0), topScorer(0), allPlayersTree(), allTeamsTree() {}

world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}


StatusType world_cup_t::add_team(int teamId, int points)
{
	if(teamId<=0||points)
        return StatusType::INVALID_INPUT;
    Team t1(teamId,points);
    if(allTeamsTree.search(t1)== nullptr)
        return StatusType::FAILURE;
    allTeamsTree.insert(t1);
	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_team(int teamId)
{
    if(teamId<=0)
        return StatusType::INVALID_INPUT;
    Team t1(teamId);
    if(allTeamsTree.search(t1) == nullptr)
        return StatusType::FAILURE;
    Team searchResult = *allTeamsTree.search(t1)->data;
    if(searchResult.getTeamPlayersCount() > 0)
	    return StatusType::FAILURE;
    allTeamsTree.remove(searchResult);
    return StatusType::SUCCESS;
}

StatusType world_cup_t::add_player(int playerId, int teamId, int gamesPlayed,
                                   int goals, int cards, bool goalKeeper)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_player(int playerId)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed,
                                        int scoredGoals, int cardsReceived)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
    if(teamId1 <= 0 || teamId2 <= 0 || teamId1 == teamId2)
        return StatusType::INVALID_INPUT;
    Team team1 = Team(teamId1);
    Team team2 = Team(teamId2);
    if(allTeamsTree.search(team1) == nullptr || allTeamsTree.search(team2) == nullptr){
        return StatusType::INVALID_INPUT;
    }
    team1 = *allTeamsTree.search(team1)->data;
    team2 = *allTeamsTree.search(team2)->data;
    if(team1.getTeamPlayersCount() < 11 || !team1.hasKeeper() || team2.getTeamPlayersCount() < 11 || !team2.hasKeeper())
        return StatusType::FAILURE;
    int teamOneScore = calculateScore(team1);
    int teamTwoScore = calculateScore(team2);
    if(teamOneScore > teamTwoScore)
        team1.updatePoints(TEAM_WIN);
    else if(teamOneScore < teamTwoScore)
        team2.updatePoints(TEAM_WIN);
    else{
        team1.updatePoints(TEAM_DRAW);
        team2.updatePoints(TEAM_DRAW);
    }
    team1.updateGamesPlayed();
    team2.updateGamesPlayed();
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_num_played_games(int playerId)
{
	if(playerId <= 0)
        return output_t<int>(StatusType::INVALID_INPUT);
    Player playerToFind = Player(playerId);
    if(allPlayersTree.search(playerToFind) == nullptr)
        return output_t<int>(StatusType::INVALID_INPUT);
    playerToFind = *allPlayersTree.search(playerToFind)->data;
    return output_t<int>(playerToFind.getGamesPlayed());
}

output_t<int> world_cup_t::get_team_points(int teamId) {
    if(teamId <= 0)
        return output_t<int>(StatusType::INVALID_INPUT);
    Team teamToFind = Team(teamId);
    if(allPlayersTree.search(teamId) == nullptr)
        return output_t<int>(StatusType::INVALID_INPUT);
    teamToFind = *allTeamsTree.search(teamToFind)->data; // leak??????
    return output_t<int>(teamToFind.getPoints());
}

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
	if(teamId1 <= 0 || teamId2 <= 0 || newTeamId <= 0 || teamId1 ==teamId2)
        return StatusType::INVALID_INPUT;
    Team team1(teamId1);
    Team team2(teamId2);
    Team newTeam(newTeamId);
    if(allTeamsTree.search(team1) == nullptr || allTeamsTree.search(team2) == nullptr)
        return StatusType::FAILURE;
    team1 = *allTeamsTree.search(team1)->data; // possible leak??????
    team2 = *allTeamsTree.search(team2)->data; // possible leak???????
    if(allTeamsTree.search(newTeam) != nullptr){
        if(newTeamId != teamId1 && newTeamId!= teamId2)
            return StatusType::FAILURE;
        else{
            if(newTeamId == teamId1){
                /// move to team 1
                team1.moveTeam(team2);
                allTeamsTree.remove(team2);
                // delete team 2
            }else{
                /// move to team 2
                team2.moveTeam(team1);
                allTeamsTree.remove(team1);
                // delete team 1
        }
    }
    }else{
        /// create new team and move team 1 then team 2 (debatable)
    }
    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_top_scorer(int teamId) {
    if(teamId == 0)
        return output_t<int>(StatusType::INVALID_INPUT);
    Team team = Team(teamId);
    if(teamId > 0) {
        if (allTeamsTree.search(team) != nullptr) {
            if (allTeamsTree.search(team)->data->getTeamPlayersCount() > 0)
                return output_t<int>(allTeamsTree.search(team)->data->getTopScorer());
            else
                return output_t<int>(StatusType::FAILURE);
        }
        else
            return output_t<int>(StatusType::FAILURE);
    }
    if(teamId < 0){
        if(allPlayersCount > 0)
            return output_t<int>(topScorer);
        else
            return output_t<int>(StatusType::FAILURE);
    }
}

output_t<int> world_cup_t::get_all_players_count(int teamId)
{
	if(teamId == 0)
        return output_t<int>(StatusType::INVALID_INPUT);
    Team team = Team(teamId);
    if(teamId > 0){
        return output_t<int>(allTeamsTree.search(team)->data->getTeamPlayersCount()); // leak??????
    }
    return output_t<int>(allPlayersCount);
    //static int i = 0;
    //return (i++==0) ? 11 : 2;
}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{
	if(teamId == 0 || output == nullptr)
        return StatusType::INVALID_INPUT;
    if(teamId < 0){
        if(allPlayersCount > 0) {
            Player *playersByOrder = new Player[allPlayersCount];
            allPlayersTree.inorder(playersByOrder);
            for(int i = 0; i < allPlayersCount; i++){
                output[i] = playersByOrder[i].getId();
            }
            return StatusType::SUCCESS;
        }
        return StatusType::FAILURE;
    }
    Team team = Team(teamId);
    if(teamId > 0){
        if(allTeamsTree.search(team) != nullptr){
            team = *allTeamsTree.search(team)->data; // does this cause memory leak (created at line 167 first)
            if(team.getTeamPlayersCount() > 0){
                Player *playersByOrder = new Player[team.getTeamPlayersCount()];
                team.teamPlayersInOrder(playersByOrder);
                for(int i = 0; i < team.getTeamPlayersCount(); i++){
                    output[i] = playersByOrder[i].getId();
                }
                return StatusType::SUCCESS;
            }
        }
        return StatusType::FAILURE;
    }
    //output[0] = 4001;
    //output[1] = 4002;
	//return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_closest_player(int playerId, int teamId)
{
	// TODO: Your code goes here
	return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{
	// TODO: Your code goes here
	return 2;
}

