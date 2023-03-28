#include <iostream>
#include <map>
#include <string>

#pragma once
using namespace std;

class workout
{
private:    
    int yards; 
    int difficulty;

public:
    workout(int yard, int difficulty);
    int get_yards();
    void generate_workout();
};