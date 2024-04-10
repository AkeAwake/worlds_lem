// Grabs all of the other code in any other files that could be used in this file
#include "main.h"

// Digital outputs for different mechanisms
pros::ADIDigitalOut leftWing('E', false); // Front Left Wing in port E
pros::ADIDigitalOut rightWing('C', false); // Front Right Wing in port C
pros::ADIDigitalOut backleftWing('D', false); // Back Left Wing in port D
pros::ADIDigitalOut backrightWing('A', false); // Back Right Wing in port A


// Function to set the states of wings and other mechanisms
void setWings() {

    // Front Wing logic, to be ran when both the buttons are presed, with the shift key
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        
        leftWing.set_value(true); // turns front left wing on
        rightWing.set_value(true); // turns front right wing on

        Intake1 = -127; // reverses the intake when the front wings are out, makes it easier to drive
        Intake2 = -127; // reverses the intake when the front wings are out, makes it easier to drive

    }
    
    // Else statement added to make wings come back in if the buttons are not being pressed
    else {

        leftWing.set_value(false); // turns off front left wing
        rightWing.set_value(false); // turns off front right wing

    }

    // Back right wing logic, pressed with scuffs
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        
        backrightWing.set_value(true); // turns on back right wing

    }
    
    // Else statement added to make wings come back in if the buttons are not being pressed
    else {

        backrightWing.set_value(false); // turns off back right wing

    }

    // Back left wing toggle logic, pressed with scuffs
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        
        backleftWing.set_value(true); // turns on back left wing

    }
    
    // Else statement added to make wings come back in if the buttons are not being pressed
    else {

        backleftWing.set_value(false); // turns off back left wing

    }
}

// Setup functions to make testing and autonomous easier

// Simple Function to turn on both wings for Autonomous or testing
void wingsOn() {
    leftWing.set_value(true); // Turn on Front Left Wing
    rightWing.set_value(true); // Turn on Front Right Wing
}

// Simple Function to turn off both wings for Autonomous or testing
void wingsOff() {
    leftWing.set_value(false); // Turn off Front Left Wing
    rightWing.set_value(false); // Turn off Front Right Wing
}

// Simple Function to turn on both back wings for Autonomous or testing
void backwingsOn() {
    backleftWing.set_value(true); // Turn on Back Left Wing
    backrightWing.set_value(true); // Turn on Back Right Wing
}

// Simple Function to turn off both back wings for Autonomous or testing
void backwingsOff() {
    backleftWing.set_value(false); // Turn off Back Left Wing
    backrightWing.set_value(false); // Turn off Back Right Wing
}
