// you can use includes, for example:
// #include <algorithm>
#include <asm-generic/errno.h>
#include <iostream>
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int get_time(char *array, int &arr_len, int ditch_scoot, bool has_scoot);

int solution(string &R) {
    // write your code in C++14 (g++ 6.2.0)

    bool has_scoot = true;
    int time_tot = 0;

    int arr_len = R.length();
    char array[arr_len + 1];
    strcpy(array, R.c_str());

    // int S_time_add = 0;
    // for (int i = arr_len - 1; array[i] == 'S' && i >= 0; i--) {
    //     S_time_add += 30;
    // }

    time_tot = get_time(array, arr_len, 0, has_scoot); // puts the first attempt (without a scooter) as the total

    for (int i = 0; i < arr_len; i++) { // gets all times if the scooter is ditched after every point
        int new_time = get_time(array, arr_len, i + 1, has_scoot);
        time_tot = (new_time < time_tot) ? new_time : time_tot; // sees if the time is smaller and replaces total
        has_scoot = true;
    }

    // time_tot += S_time_add;

    return time_tot;
}

int get_time(char *array, int &arr_len, int ditch_scoot, bool has_scoot) {

    int time = 0;

    for (int i = 0; i < arr_len; i++) {
        if ( (i >= ditch_scoot) ) {         // checks if you ditch the scooter at this point
            has_scoot = false;
        }
        if (has_scoot) {
            if( (array[i] == 'S') ) {
                time += 40;
            } else if ( (array[i] == 'A') ) {
            time += 5;
            }
        } else {
            if( (array[i] == 'S') ) {
                time += 30;
            } else if ( (array[i] == 'A') ) {
            time += 20;
            }
        }
    }
    return time;
}
