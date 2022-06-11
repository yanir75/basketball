
#include "Team.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
namespace basketball {
    class Scheduler {
        std::vector<Team *> teams1;
        std::vector<Team *> teams2;
        int round;
        unsigned int index;
    public:
        explicit Scheduler(std::vector<Team> &teams);
        int match();
    };
}

