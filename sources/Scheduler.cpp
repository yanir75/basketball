//
// Created by yanir on 6/11/2022.
//

#include "Scheduler.hpp"
constexpr unsigned int TEAMS_SIZE = 20;
constexpr int rounds = 38;
basketball::Scheduler::Scheduler(std::vector<Team> &teams) {
    if(teams.size()==TEAMS_SIZE){
        for (unsigned int i = 0; i < TEAMS_SIZE/2; ++i) {
            teams1.push_back(&teams[i]);
            teams2.push_back(&teams[i+TEAMS_SIZE/2]);
        }
        round = 0;
        index = 0;
    }

}

int basketball::Scheduler::match() {
    if(round <rounds/2) {
        if (index >= TEAMS_SIZE / 2){
            index = 0;
            teams1.insert(teams1.begin()+1,teams2[0]);
            teams2.push_back(teams1[teams1.size()-1]);
            teams1.erase(teams1.begin()+(unsigned int)(teams1.size()-1));
            teams2.erase(teams2.begin());
            round++;
            if(round >=rounds/2){
                return -1;
            }
        }
        basketball::Game g;
        g.winner(*teams1[index],*teams2[index]);
        teams2[index]->games++;
        teams1[index]->games++;
        index++;
    }
    else{
        if (index >= TEAMS_SIZE / 2){
            index = 0;
            teams1.insert(teams1.begin()+1,teams2[0]);
            teams2.push_back(teams1[teams1.size()-1]);
            teams1.erase(teams1.begin()+(unsigned int)(teams1.size()-1));
            teams2.erase(teams2.begin());
            round++;
            if(round >=rounds){
                return 0;
            }
        }
        basketball::Game g;
        g.winner(*teams2[index],*teams1[index]);
        teams2[index]->games++;
        teams1[index]->games++;
        index++;

    }
    return 1;
}
