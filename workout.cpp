#include "workout.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <map>

using namespace std;

workout::workout(int yard, int difficulty)
{
    this->yards = yard;
    this->difficulty = difficulty * 2;
}

int workout::get_yards()
{
    return this->yards;
}

//
// generate_workout(): generates and prints workout
//

void workout::generate_workout()
{
    // get the system time.
    unsigned seed = time(0);
   
    // seed the random number generator.
    srand(seed);

    // warm up at least 400 yards
    int remaining_yards = this->get_yards() - 400;
    int total_yards = 400;

    // diff possible strokes based on difficulty
    string diff_strokes[6] = {"Freestyle", "Kick", "Breaststroke", "IM", "IM", "Butterfly"};
    int diff_lengths[4] = {50, 75, 100, 200};
    int diff_times[6] = {2, 3, 5, 4, 6, 8};
     
    string cur_stroke;
    int cur_length;
    int cur_times; 

    cout << "Workout: " << endl;
    cout << endl;
    cout << "WARM-UP: " << '\n' << "    200 yd Freestyle" << '\n' << "    200 yd Kick" << endl;
    cout << endl;

    cout << "MAIN SET: " << endl;
    // generates different parts of the workout
    while (remaining_yards >= 200)
    {
        // choose a stroke
        cur_stroke = diff_strokes[rand() % this->difficulty];  

        // split by 200 yards, 100 yards, 75 yards, or 50 yards
        cur_length = diff_lengths[rand() % 4];

        // choose how many times
        if (cur_length == 200)
        {
            cur_times = diff_times[rand() % 2];
        }
        else if (cur_length == 100)
        {
            cur_times = diff_times[rand() % 3] + 2;
        }
        else
        {
            cur_times = diff_times[rand() % 3] + 3;
        }
 
        remaining_yards = remaining_yards - (cur_length * cur_times);
        total_yards = total_yards + (cur_length * cur_times);

        cout << "    " << cur_times << " x " << cur_length << " yd " << cur_stroke << endl;
    }

    cout << endl;
    cout << "WARM-DOWN: " << endl;

    // generate yards to cool down 
    if (remaining_yards > 0)
    {
        cout << "    " << remaining_yards << " yd cool-down" << endl;
        total_yards = total_yards + remaining_yards;
    }
    else 
    {
        cout << "    " << "100 yd cool-down" << endl;
        total_yards = total_yards + 100;
    }

    cout << endl;
    cout << "TOTAL YARDS: " << total_yards << " yd" << endl;
    cout << endl;
}