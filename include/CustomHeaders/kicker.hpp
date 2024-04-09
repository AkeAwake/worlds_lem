// ensures that PROS is working
#define PROS_USE_LITERALS
#include "api.h"

// Initalizes the functions to be used in the main.cpp or other files

int setKicker(); // sets the kicker and the hang with the PTO

int tokickerPTO(); // sets the function to PTO to the kicker

int tohangPTO(); // sets the function to PTO to the hang

void KickerON(); // makes a function to just spin the kicker

void KickerOFF(); // makes a function to turn off the kicker