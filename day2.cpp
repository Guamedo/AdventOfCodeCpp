#include <iostream>
#include <fstream>
#include <vector>

#include "day2.h"

using namespace std;

int execute_program(vector<int> program, int noun, int verb){
    program[1] = noun;
    program[2] = verb;
    int index = 0;
    while(program[index] != 99){
        switch(program[index]){
            case 1:
                program[program[index + 3]] = program[program[index + 1]] + program[program[index + 2]];
                break;
            case 2:
                program[program[index + 3]] = program[program[index + 1]]*program[program[index + 2]];
                break;
            default:
                cout << "ERROR: Unknown operator code (" << program[index] << ")" << endl;
        }
        index += 4;
    }
    return program[0];
}

void day2(){
    ifstream file("inputs/input2.txt");
    vector<int> program;

    int num;
    char sep;
    file >> num;
    program.push_back(num);
    while(file >> sep >> num){
        program.push_back(num);
    }
    cout << execute_program(program, 12, 2) << endl;
}

void day2_star(){
    ifstream file("inputs/input2.txt");
    vector<int> program;

    int num;
    char sep;
    file >> num;
    program.push_back(num);
    while(file >> sep >> num){
        program.push_back(num);
    }

    bool end = false;
    for(int noun = 0; noun < 100 && !end; noun++){
        for(int verb = 0; verb < 100 && !end; verb++){
            if(execute_program(program, noun, verb) == 19690720){
                cout << 100*noun + verb << endl;
                end = true;
            }
        }
    }
}