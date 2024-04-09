// Adding the other files to implement the code contained in them
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "autoSelect/selection.h"
#include "CustomHeaders/globals.hpp"
#include "CustomHeaders/intake.hpp"
#include "CustomHeaders/wings.hpp"
#include "CustomHeaders/kicker.hpp"
#include "CustomHeaders/drive.hpp"
#include "gif-pros/gifclass.hpp"
//#include "lemlib/logger/stdout.hpp"

// initalizing the inertial sensor in port 6 to be used to tare
pros::Imu imu_sensor(6);


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(true); // calibrate sensors
    selector::init(); // initalizes the auton selector

    // printing out the x, y and heading to the brain to make sure the robot is moving the correct distance
    pros::Task screenTask([&]() {
        //lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", ((chassis.getPose().x)-42.249)); // x
            pros::lcd::print(1, "Y: %f", ((chassis.getPose().y)+58.563)); // y
            pros::lcd::print(2, "Theta: %f", ((chassis.getPose().theta)+146.877)); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}


/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
    
    drivehold(); // setting the drivetrain to hold, making consistency better

    // Red Auton 1
    if(selector::auton == 1){
        rushsixball();
    }
    // Red Auton 2
    if(selector::auton == 2){
        awprush();
    }
    // Red Auton 3
    if(selector::auton == 3){
        elimsrush();
    }
    // Red Auton 4
    if(selector::auton == 4){
        
    }
    // Blue Auton 1
    if(selector::auton == -1){
        rushsixball();
    }
    // Blue Auton 2
    if(selector::auton == -2){
        awprush();
    }
    // Blue Auton 3
    if(selector::auton == -3){
        elimsrush();
    }
    // Blue Auton 4
    if(selector::auton == -4){
        
    }
    // Skills Autonomous
    if(selector::auton == 0){
        skills();
    }
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // controller
    // loop to continuously update motors
    while (true) {

        joystickvalues(); // Runs the code for drivetrain curves and split arcade
        setKicker(); // Runs the code for the kicker and the hang (because of the PTO)
        setIntake(); // Runs the code for the intake
        setWings(); // Runs the code for the wings
        drivecoast(); // Makes the drivetrain coast and not hold for driver, making the robot drift
        setBrakes(); // Makes the Intake, and the 2 Kicker motors coast
        automacro(); // Runs the macro for skills, where it runs the first part of the autonomous during driver
        intakedeploy(); // Runs the macro for the intake deploy. If the Intake dosent deploy in driver, Lucas can deploy it in driver

        // Adds the monkey image to the brain if you select an auton
        //pros::screen::touch_callback(image, TOUCH_PRESSED);
        

        // delay to save resources
        pros::delay(10);
    }

    
}