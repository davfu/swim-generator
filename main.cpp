#include <iostream>
#include <map>
#include <set>
#include <string>
#include "workout.h"
using namespace std;

int main()
{
    cout << endl;
    cout << "Generate a Swim Workout" << endl;
    cout << "***********************" << endl;
    cout << endl;

    int yards;
    int difficulty;

    cout << "Enter approximate distance of workout (over 1000 yards): ";
    cin >> yards;
    cout << "Enter difficulty of workout [1 (easy), 2 (medium), 3 (hard)]: ";
    cin >> difficulty;
    cout << endl;

    workout *w = new workout(yards, difficulty);
    w->generate_workout();

    return 0;
}