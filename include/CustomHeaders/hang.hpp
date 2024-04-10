// ensures that PROS is working
#define PROS_USE_LITERALS
#include "api.h"

// Initalizes the functions to be used in the main.cpp or other files

int todrivePTO(); // sets the function to PTO to the kicker

int tohangPTO(); // sets the function to PTO to the hang

void spinhang(int hangvolts); // sets the function to make it easier to set the voltage values for each of the drivetrain motors

int setHang(); // sets the kicker and the hang with the PTO