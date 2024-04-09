// Grabs all of the other code in any other files that could be used in this file
#include "main.h"

// boolean vairables setting up the toggle function
bool intaketoggle = false;
bool pressed = false;

// Intake function, to be ran in the Main.cpp in a while true loop
void setIntake(){

        // Senses if the Intake button is on. This also makes sure that the shiftkey is not being pressed to run the intake
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

            Intake = -127; // reverses intake. This is before turning the intake on, as old logic would have the reverse override the toggle

        }
    
        // Senses if the Intake button is on. This also makes sure that the shiftkey is not being pressed to run the intake
        else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

            Intake = 127; // Turns intake on with max voltage.

        }

        // This is necessary so that when the button is not being held, the intake turns off. Without this the intake would always be on
        else {

            Intake = 0; // turns the intake off.

        }

}

// Simple function to just run the intake. Helps in testing or in autonomous
void intakeON(){

    Intake = 127; // Spins intake at max voltage

}

// Simple function to just reverse the intake. Helps in testing or in autonomous
void intakeREVERSE(){

    Intake = -127; // Reverses intake at max voltage

}

// Simple function to turn off the intake. Helps in testing or in autonomous
void intakeOFF(){

    Intake = 0; // Sets intake voltage to zero

}