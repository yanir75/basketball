//
// Created by yanir on 6/11/2022.
//

#include "League.hpp"
constexpr int MAX_TEAMS =20;
constexpr int NAME_SIZE =12;
constexpr int CHAR_NUM =26;
constexpr int FIRST_CHAR =97;
constexpr double maximum=100;
std::string gen(){
    std:string name;
    for(int i=0;i<NAME_SIZE;i++){
        name+=(char)(rand()%CHAR_NUM+FIRST_CHAR);
    }
    return name;
}
bool basketball::League::contains(const basketball::Team& team) {
    for(Team &t: teams){
        if(t.team == team.team){
            return true;
        }
    }
    return false;
}
void basketball::League::fill(unsigned int num) {
    int i = 0;
    while(teams.size() < MAX_TEAMS && i<num){
        double tal = (double)(rand() %100) / maximum;
        add(Team(gen(),tal));
    }
}

void basketball::League::add(const basketball::Team& team) {
    if(!contains(team) && teams.size()<MAX_TEAMS){
        teams.push_back(team);
    }
}




vector<basketball::Team> basketball::League::leading(unsigned int num) {
    auto first = teams.begin() ;
    auto last = teams.begin() + num;
    vector<basketball::Team> newVec(first, last);
    return newVec;
}

void basketball::League::sort() {
    vector<basketball::Team> teas;
    for (int  j = 0; j <MAX_TEAMS; j++) {
        unsigned int index = 0;
        for (unsigned int i = 1; i < teams.size(); i++) {
            if (teams[i].wins < teams[index].wins) {
                index = i;
            }
        }
        teas.push_back(teams[index]);
        teams.erase(teams.begin() + index);
    }
    teams=teas;
}

int basketball::League::winstreak() {
    int max=0;
    for (basketball::Team &t:teams) {
        max = t.win_max > max ? t.win_max : max;
    }
    return max;
}

int basketball::League::looserstreak() {
    int max=0;
    for (basketball::Team &t:teams) {
        max = t.lose_max > max ? t.lose_max : max;
    }
    return max;
}

int basketball::League::less_than_scored() {
    int count=0;
    for (basketball::Team &t:teams) {
        count = t.score > t.score_on_us ? count+1 : count;
    }
    return count;
}

std::string basketball::League::top_scorer() {
    std::string best;
    int max =0;
    for(unsigned int i=0;i<MAX_TEAMS;i++){
        if(teams[i].score >max){
            max = teams[i].score;
            best = teams[i].team;
        }
    }
    return best;
}

std::string basketball::League::top_scored_on_us() {
    std::string best;
    int max =0;
    for(unsigned int i=0;i<MAX_TEAMS;i++){
        if(teams[i].score_on_us >max){
            max = teams[i].score_on_us;
            best = teams[i].team;
        }
    }
    return best;
}




