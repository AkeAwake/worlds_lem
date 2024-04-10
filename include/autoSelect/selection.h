// makes sure that pros is working
#pragma once

// make a string of autons
#include <string>

//selector configuration
#define HUE 360 // color in hue
#define DEFAULT 1 // defaults the program if no auton is selected
#define AUTONS "N Safe", "N Elim","N Rush", "6 Touch", "7 Mid", "7 Bar", "Do Nothing" // list of autons

// writes the code for the selector
namespace selector{

    extern int auton; // makes the auto run
    const char *b[] = {AUTONS, ""}; // defines the autons listed from before
    void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b); // Initalizes the selector

}
