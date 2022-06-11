#include <iostream>
#include "sources/League.hpp"
#include "sources/Scheduler.hpp"
int main()
{
    basketball::League l;
    l.fill(20);
    basketball::Scheduler s(l.teams);
    int i =0;
    while (s.match()){
        i++;
    }
    for(unsigned int i =0;i<20;i++){
        cout << l.teams[i].games << endl;
    }

}

