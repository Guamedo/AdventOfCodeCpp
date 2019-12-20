#include <iostream>

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"

using namespace std;

int main() {
    int day;

    cout << "Select a day:";
    cin >> day;
    switch(day){
        case 1:
            cout << "Day 1 output:" << endl;
            day1();
            cout << "Day 1* output:" << endl;
            day1_star();
            break;
        case 2:
            cout << "Day 2 output:" << endl;
            day2();
            cout << "Day 2* output:" << endl;
            day2_star();
            break;
        case 3:
            cout << "Day 3 output:" << endl;
            day3();
            cout << "Day 3* output:" << endl;
            day3_star();
            break;
        case 4:
            cout << "Day 4 output:" << endl;
            day4();
            break;
        default:
            cout << "Day "<< day << " is not implemented yet" << endl;
    }
    return 0;
}
