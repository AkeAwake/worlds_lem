// ensures that PROS is working
#define PROS_USE_LITERALS
#include "api.h"

// Initalizes the functions to be used in the main.cpp or other files

void setIntake(); // sets the function to spin the intake

void intakeON(); // sets the helper function to turn on the intake in auto

void intakeREVERSE(); // sets the helper function to reverse the intake in auto

void intakeOFF(); // sets the helper function to turn the intake off in auto