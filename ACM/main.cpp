/*** Created by reza nazeri on 2015/25/12 ***/

#include <iostream>
#include <chrono>
#include <ctime>
#include "Team.h"
//#include "List.h"

using namespace std;
using namespace std::chrono;

int main() {
    milliseconds ms = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );
    cout << ms.count() << endl;

    system_clock::time_point p = system_clock::now();

    time_t t = system_clock::to_time_t(p);
    cout << std::ctime(&t) << std::endl;

//    List<Team> team;
//
//    Team temp;
//    temp.getData();
//    team.addLast(temp);
//    team.printTeam();
    cout << "End :)\n";
    return 0;
}