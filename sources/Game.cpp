//
// Created by yanir on 6/11/2022.
//

#include "Game.hpp"
#include <random>
constexpr float EXPECTATION_A = 75;
constexpr float VARIANCE_A = (50.0*50.0)/12.0;
constexpr int MIN_SCORE_A =55;
constexpr int MAX_SCORE_A =100;
constexpr int DEFAULT_NUM =-1;
constexpr int MAX_SCORE_B =100;
constexpr int MIN_SCORE_B =50;
constexpr int TRIES =10;


basketball::Team basketball::Game::winner(Team &A,Team &B) {
    games++;
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{EXPECTATION_A,VARIANCE_A};
    int scoreA = DEFAULT_NUM;
    while (scoreA <MIN_SCORE_A || scoreA >MAX_SCORE_A){
        scoreA = (int)(d(gen));
    }

    int scoreB = DEFAULT_NUM;
    while (scoreB <MIN_SCORE_B || scoreB >MAX_SCORE_B){
        scoreB = (int )(d(gen));
    }
    int maxA = 0;
    for(int i=0;i<A.talent*TRIES;i++){
        int num = (int)rand()%TRIES;
        maxA = num > maxA ? num : maxA;
    }
    int maxB = 0;
    for(int i=0;i<A.talent*TRIES;i++){
        int num = (int)rand()%TRIES;
        maxB = num > maxB ? num : maxB;
    }
    A.score+=scoreA+maxA;
    A.score_on_us += scoreB+maxB;
    B.score += scoreB+maxB;
    B.score_on_us+=scoreA+maxA;
    basketball::Team &winner = scoreA+maxA > scoreB+maxB ? A : B;
    basketball::Team &loser = scoreA+maxA <= scoreB+maxB ? A : B;
    loser.win_len = 0;
    loser.lose_len++;
    loser.lose_max = loser.lose_len > loser.lose_max ? loser.lose_len : loser.lose_max;
    winner.win_len++;
    winner.win_max = winner.win_len > winner.win_max ? winner.win_len : winner.win_max;
    winner.lose_len = 0;
    winner.wins++;
    return winner;
}
