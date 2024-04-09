#include "main.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// drive motors
pros::Motor frontLeft(-20, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); // left front motor. port 11, reversed
pros::Motor middleLeft(-10, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); // left middle motor. port 12, reversed
pros::Motor backLeft(-9, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); // left back motor. port 13, reversed
pros::Motor frontRight(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS); // right front motor. port 18
pros::Motor middleRight(2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS); // right middle motor. port 19
pros::Motor backRight(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS); // right back motor. port 21
pros::Motor Kicker(12, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS); // catapult motor. port 14, reversed
pros::Motor Kicker2(16, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); // catapult motor. port 14, reversed
pros::Motor Intake(21, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); // intake motor. port 16, reversed


// motor groups
pros::MotorGroup leftMotors({frontLeft, middleLeft, backLeft}); // left motor group
pros::MotorGroup rightMotors({frontRight, middleRight, backRight}); // right motor group

// Inertial Sensor on port 8
pros::Imu imu(6);

// vertical tracking wheel in port 7, reversed direction
pros::Rotation verticalEnc(7, true);
// horizontal tracking wheel. 2.75" diameter, 3.7" offset, back of the robot
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, 1);

// drivetrain settings
lemlib::Drivetrain drivetrain {
    &leftMotors, // left drivetrain motors
    &rightMotors, // right drivetrain motors
    10.5, // track width
    3.25, // wheel diameter
    450, // wheel rpm
    8 //chase power
};

// forward/backward PID
lemlib::ControllerSettings linearSettings {
    10, // kP
    0, //kI
    30, // kD
    0, //windupRange
    1, // smallErrorRange
    50, // smallErrorTimeout
    3, // largeErrorRange
    250, // largeErrorTimeout
    2 // slew rate 
};
 
// turning PID
lemlib::ControllerSettings angularSettings {
    2, // kP
    0, //kI 1
    10, // kD 30
    0, //windupRange
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    250, // largeErrorTimeout
    0 // slew rate 
};

// sensors for odometry
// note that in this example we use internal motor encoders, so we don't pass vertical tracking wheels
lemlib::OdomSensors sensors {
    &vertical, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &imu // inertial sensor
};



// create the chassis
lemlib::Chassis chassis(drivetrain, linearSettings, angularSettings, sensors);