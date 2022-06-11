
#include "doctest.h"
#include "sources/League.hpp"
#include "sources/Scheduler.hpp"


using namespace basketball;
#define MIN_SCORE 19*50+19*55
#define MAX_SCORE 38*110
TEST_CASE("Good input") {
    League l;
    l.fill(20);
    CHECK(l.teams.size()==20);
    basketball::Scheduler s(l.teams);
    while (s.match());
    for(unsigned int i=0;i<l.teams.size();i++){

        for(unsigned int j=i+1;j<l.teams.size();j++){
            CHECK(l.teams[i].team!=l.teams[j].team);
            CHECK(l.teams[i].score >= MIN_SCORE);
            CHECK(l.teams[i].score <= MAX_SCORE);
            CHECK(l.teams[i].games == 38);
            CHECK(l.teams[i].wins <= 38);
            CHECK(l.teams[i].wins >=0);
        }
    }

}

TEST_CASE("Bad input") {
}


/* Add more test cases here */