#include <iostream>
#include <string>
#include <sstream>

#include "day4.h"

using namespace std;

void day4(){
    int cont = 0;
    for(int i = 178416; i < 676461; i++){
        stringstream ss;
        ss << i;
        auto str_num = ss.str();
        bool cond1 = true, cond2 = false;
        for(int j = 0; j < str_num.size()-1; j++){
            if(str_num[j] > str_num[j+1]){
                cond1 = false;
            }
            if(str_num[j] == str_num[j+1]){
                cond2 = true;
            }
            if(cond1 && cond2){
                cont++;
            }
        }
    }
    cout << cont << endl;
}