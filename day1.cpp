#include <iostream>
#include <fstream>
#include <cmath>

#include "day1.h"

using namespace std;

void day1(){
    ifstream file("inputs/input1.txt");
    int num;
    int sum = 0;
    while(file >> num){
        sum += num/3 - 2;
    }
    cout << sum << endl;
}

void day1_star(){
    ifstream file("inputs/input1.txt");
    int num;
    int sum = 0;
    while(file >> num) {
        num = int(floor(float(num)/3.0)) - 2;
        while (num > 0){
            sum += num;
            num = int(floor(float(num)/3.0)) - 2;
        }
    }
    cout << sum << endl;
}