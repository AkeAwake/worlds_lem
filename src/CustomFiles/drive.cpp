// Includes any libraries added, and making sure that the code is implemented correctly
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "CustomHeaders/globals.hpp"

bool drivertoggle = false;
bool presseddrivertoggle = false;

pros::ADIDigitalOut offratchet('B', false); // Ratchet puller in port B

// Makes the Intake coast and not hold
void setBrakes() {
  Intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

// Defines the drivetrain to hold its position. This is run in autonomous, or when we are matchloading
void drivehold(){
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  middleRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  middleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // Added making the left and right motors groups hold because lemlib sometimes has issues with holding single motors
  leftMotors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  rightMotors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
}

// Defines the drivetrain to coast, making drifting possible. This is run in driver, making it easier to drive.
void drivecoast(){
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  middleRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  middleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  // Added making the left and right motors groups coast because lemlib sometimes has issues with holding single motors
  leftMotors.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
  rightMotors.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
}

// Defines the macro for autonomous, if the left key is pressed, it runs the begenning part of the auton and resets the driver inertial sensor and chassis.
void automacro(){

  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) and !presseddrivertoggle){
    
    drivertoggle = !drivertoggle;
    presseddrivertoggle = true;

  }

  if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        
    presseddrivertoggle = false; // the button has been released, be ready for the next press

  }

  if (drivertoggle){

    drivehold();
    
    //drivermacro();

  }

  if (!drivertoggle){

    drivecoast();

  }

}

// Defines the intake deploy macro so that if it dosent come down in auto, it can still deploy
void intakedeploy(){

  // get button press from down
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

    autohang();

  }

}

// Defines the deadzone, or to where the minimum distance you have to move the joystick for the robot to move
#define JOYSTICK_DEADZONE 5

// Defines the t vairable, apart of the joystick curve calculation. The higher value, the more you have to move the joystick
int t = 12;

int getExpoValue(int joystickValue)
{
    int output = 0;
    // Ignore joystick input if it's too small
    if(abs(joystickValue) > JOYSTICK_DEADZONE){
      // Direction is either 1 or -1, based on joystick valu

      // Plug joystick value into exponential function
      //output = direction * (1.2 * pow(1.0356, abs(joystickValue)) - 1.2 + 0.2 * abs(joystickValue));
      output = (pow(2.1, -(t/10)) + pow(2.1, (abs(joystickValue)-127)/10) * (1-pow(2.1, -(t/10))) * joystickValue);
    }
    return output;
}

// The output is then used with whatever type of driver control layout (tank, arcade, etc.) you prefer
// A quick example of tank drive in opControl:

void joystickvalues(){
    // Get joystick values with exponential drive
    //int leftPower = getExpoValue(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) + getExpoValue(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
    //int rightPower = getExpoValue(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) - getExpoValue(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));

    // Gets joystick values with non exponential drive
    int leftPower = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) + (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
    int rightPower = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) - (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));

    // sets the power to the right motors from the movement of the joysticks
    frontRight.move(rightPower);
    middleRight.move(rightPower);
    backRight.move(rightPower);

    // sets the power to the left motors from the movement of the joysticks
    frontLeft.move(leftPower);
    middleLeft.move(leftPower);
    backLeft.move(leftPower);
}