

#include "Team.hpp"

basketball::Team::Team(const std::string &name, double tal) {
    team = name;
    talent = tal;
    games = 0;
    wins = 0;
    score = 0;
    score_on_us = 0;
    win_max = 0;
    win_len = 0;
    lose_max = 0;
    lose_len = 0;
}


