// ensures that PROS is working
#define PROS_USE_LITERALS
#include "api.h"

// Initalizes the functions to be used in the main.cpp or other files

void setBrakes(); // sets the intake to coast

void drivehold(); // sets the drivetrain to hold during autonomous and during matchloading

void drivecoast(); // sets the drivetrain to coast during driver

int getExpoValue(int joystickValue); // sets a function to get make the drivetrain inputs exponential

void joystickvalues(); // makes the function to control the motors

void automacro(); // sets the macro for the start of autonomous skils for driver

void intakedeploy(); // sets the macro to deploy the intake just in case