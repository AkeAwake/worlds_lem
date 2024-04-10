// ensures that PROS is working
// This is a c++ thing, as the autons.cpp, as well as the autons.hpp file is not included in custom headers
#pragma once

void test(); // sets up a testing auton for pure pursuit movements

void wingintask(); // sets a task for bringing both front wings in

void wingouttask(); // sets up a task for pushing both front wings out

void leftwingintask(); // sets up a task for bringing the left front wing in

void leftwingouttask(); // sets up a task for pushing the front left wing out

void rightwingintask(); // sets up a task for bringing the front right wing in

void rightwingouttask(); // sets up a task for pushing the front right wing out

void backwingintask(); // sets up a task for bringing both back wings in

void backwingouttask(); // sets up a task for pushing both back wings out

void backleftwingintask(); // sets up a task for bringing the back left wing in

void backleftwingouttask(); // sets up a task for pushing the back left wing out

void backrightwingintask(); // sets up a task for bringing the back right wing in

void backrightwingouttask(); // sets up a task for pushing the back right wing out

void drivermacro(); // sets up the driver macro to be ran for driver skills

int start(); // sets up a task for the rush nearside to be ran while the robot is moving towards the ball in the center of the field

int intakedeploy(); // sets up a task for an intake deploy to help smooth out the auton making process

void normalsixball(); // sets up the auto for getting sixballs on the farside

void RushNear(); // sets up the auto for rushing to the middle on the nearside

void nearsafe();

void nearelims();

void nearrush();

void sixballtouch();

void sevenballbar();

void sevenballmid();

void rushsixball();

void awprush();

void elimsrush();

int autotokickerpto();

void drivermacro();

void skills();