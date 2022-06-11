#include <string>
#pragma once
namespace basketball {
    class Team {
    public:
        std::string team;
        double talent;
        Team(const std::string &name,double tal);
        int games;
        int wins;
        int score;
        int score_on_us;
        int win_max;
        int win_len;
        int lose_max;
        int lose_len;
    };

}


