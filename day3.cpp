#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>

#include "day3.h"

using namespace std;

struct pos{
    double x, y;
};

bool intersection_point(pos p1, pos p2, pos p3, pos p4, pos &ret){
    double det = (p1.x-p2.x)*(p3.y-p4.y) - (p1.y-p2.y)*(p3.x-p4.x);
    if(det==0){
        return false;
    }

    double t = ((p1.x-p3.x)*(p3.y-p4.y) - (p1.y-p3.y)*(p3.x-p4.x))/det;
    double u = -((p1.x-p2.x)*(p1.y-p3.y) - (p1.y-p2.y)*(p1.x-p3.x))/det;

    if(t >= 0 and t <= 1 and u >= 0 and u <= 1){
        ret.x = p1.x + t*(p2.x-p1.x);
        ret.y = p1.y + t*(p2.y-p1.y);
        return true;
    }
    return false;
}

int manhattan_distance(pos p1, pos p2){
    return int(abs(p1.x - p2.x) + abs(p1.y - p2.y));
}

void day3(){
    vector<pos> wire1, wire2;

    ifstream file("inputs/input3.txt");
    string line, path;

    // Read the first line
    getline(file, line);
    stringstream ss(line);
    wire1.push_back({0.0, 0.0});
    while(getline(ss, path, ',')){
        char dir = path[0];
        double dist = stod(path.substr(1, path.size()-1));
        switch(dir){
            case 'U':
                wire1.push_back({wire1.back().x,
                                 wire1.back().y + dist});
                break;
            case 'D':
                wire1.push_back({wire1.back().x,
                                 wire1.back().y - dist});
                break;
            case 'L':
                wire1.push_back({wire1.back().x - dist,
                                 wire1.back().y});
                break;
            case 'R':
                wire1.push_back({wire1.back().x  + dist,
                                 wire1.back().y});
                break;
            default:
                cout << "ERROR: Unknown direction" << endl;
        }
    }

    // Read the second line
    getline(file, line);
    ss.clear();
    ss.str(line);
    wire2.push_back({0, 0});
    while(getline(ss, path, ',')){
        char dir = path[0];
        double dist = stoi(path.substr(1, path.size()-1));
        switch(dir){
            case 'U':
                wire2.push_back({wire2.back().x,
                                 wire2.back().y + dist});
                break;
            case 'D':
                wire2.push_back({wire2.back().x,
                                 wire2.back().y - dist});
                break;
            case 'L':
                wire2.push_back({wire2.back().x - dist,
                                 wire2.back().y});
                break;
            case 'R':
                wire2.push_back({wire2.back().x + dist,
                                 wire2.back().y});
                break;
            default:
                cout << "ERROR: Unknown direction" << endl;
        }
    }

    int min_dist = INT_MAX;
    for(int i = 1; i < wire1.size()-1; i++){
        for(int j = 1; j < wire2.size()-1; j++){
            pos intersection{};
            if(intersection_point(wire1[i], wire1[i+1], wire2[j], wire2[j+1], intersection)){
                int m_dist = manhattan_distance({0.0, 0.0}, intersection) ;
                min_dist = (m_dist < min_dist) ? m_dist : min_dist;
            }
        }
    }
    cout << min_dist << endl;
}

void day3_star(){
    vector<pos> wire1, wire2;

    ifstream file("inputs/input3.txt");
    string line, path;

    // Read the first line
    getline(file, line);
    stringstream ss(line);
    wire1.push_back({0.0, 0.0});
    while(getline(ss, path, ',')){
        char dir = path[0];
        double dist = stod(path.substr(1, path.size()-1));
        switch(dir){
            case 'U':
                wire1.push_back({wire1.back().x,
                                 wire1.back().y + dist});
                break;
            case 'D':
                wire1.push_back({wire1.back().x,
                                 wire1.back().y - dist});
                break;
            case 'L':
                wire1.push_back({wire1.back().x - dist,
                                 wire1.back().y});
                break;
            case 'R':
                wire1.push_back({wire1.back().x  + dist,
                                 wire1.back().y});
                break;
            default:
                cout << "ERROR: Unknown direction" << endl;
        }
    }

    // Read the second line
    getline(file, line);
    ss.clear();
    ss.str(line);
    wire2.push_back({0, 0});
    while(getline(ss, path, ',')){
        char dir = path[0];
        double dist = stoi(path.substr(1, path.size()-1));
        switch(dir){
            case 'U':
                wire2.push_back({wire2.back().x,
                                 wire2.back().y + dist});
                break;
            case 'D':
                wire2.push_back({wire2.back().x,
                                 wire2.back().y - dist});
                break;
            case 'L':
                wire2.push_back({wire2.back().x - dist,
                                 wire2.back().y});
                break;
            case 'R':
                wire2.push_back({wire2.back().x + dist,
                                 wire2.back().y});
                break;
            default:
                cout << "ERROR: Unknown direction" << endl;
        }
    }

    int min_dist = INT_MAX;
    int d1 = 0, d2;
    for(int i = 0; i < wire1.size()-1; i++){
        d2 = 0;
        for(int j = 0; j < wire2.size()-1; j++){
            pos intersection{};
            if(intersection_point(wire1[i], wire1[i+1], wire2[j], wire2[j+1], intersection)){
                int d1_p = manhattan_distance(wire1[i], intersection);
                int d2_p = manhattan_distance(wire2[j], intersection);
                int dist = d1 + d1_p + d2 + d2_p;
                min_dist = (dist < min_dist) ? dist : min_dist;
            }
            d2 += manhattan_distance(wire2[j], wire2[j+1]);
        }
        d1 += manhattan_distance(wire1[i], wire1[i+1]);
    }
    cout << min_dist << endl;
}

