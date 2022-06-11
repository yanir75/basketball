#include <iostream>
#include <vector>
#include "Team.hpp"
#include "Game.hpp"
#pragma once
using namespace std;

namespace basketball {
    class League {
    public:
        vector<Team> teams;
        bool contains(const Team& team);
        void fill(unsigned int num);
        void add(const Team& team);
        void sort();
        vector<Team> leading(unsigned int num);
        int winstreak();
        int looserstreak();
        int less_than_scored();
        std::string top_scorer();
        std::string top_scored_on_us();
    };

}



