#include "Team.hpp"
#pragma once
namespace basketball{
    class Game {
        int games=0;
    public:
        Team winner(Team &A,Team &B);
    };
}