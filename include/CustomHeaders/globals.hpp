// ensures that PROS is working
#define PROS_USE_LITERALS
#include "api.h"
#include "lemlib/api.hpp"

// Initalizes the functions to be used in the main.cpp or other files

// External Motors to be used into different files
extern pros::Motor frontLeft; // Front Left Drivetrain Motor
extern pros::Motor middleLeft; // Middle Left Drivetrain Motor
extern pros::Motor backLeft; // Back Left Drivetrain Motor

extern pros::Motor frontRight; // Front Right Drivetrain Motor
extern pros::Motor middleRight; // Middle Right Drivetrain Motor
extern pros::Motor backRight; // Back Right Drivetrain Motor

// External Motor Groups to be used in different files
extern pros::MotorGroup leftMotors; // Left Drivetrain Motors Group
extern pros::MotorGroup rightMotors; // Right Drivetrain Motors Group

// External Motors outside of the Drivetrain to be used in different files
extern pros::Motor Kicker; // Kicker 11 Watt Motor
extern pros::Motor Kicker2; // Kicker 5.5 Watt Motor
extern pros::Motor Intake; // Intake 5.5 Watt Motor

// External Sensors to be used in different files
extern pros::Imu inertial; // Inertial sensor

// External Controller to be used in different files
extern pros::Controller controller; // Controller

// External Drivetrain and Chassis setup to be used in different files
extern lemlib::Drivetrain drivetrain; // Setting up the Drivetrain motors, wheels, and dimensions
extern lemlib::ControllerSettings linearSettings; // Liner PID (moving back and forth and not turning)
extern lemlib::ControllerSettings angularSettings; // Angular PID (turning back and forth and not moving)
extern lemlib::OdomSensors sensors; // Odom Sensors, Inertial and Odom Wheels
extern lemlib::Chassis chassis; // Chassis setup, combining the PID's, the sensors, and the drivetrain