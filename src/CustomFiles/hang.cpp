// Grabs all of the other code in any other files that could be used in this file
#include "main.h"

// sets the boolean toggle for the hang
bool hangdown = false; // sees if the hang button has been pressed or not to bring the hang down

// Setting up the pistons for the code to be used
pros::ADIDigitalOut PTO('H', false); // PTO piston in port H to transfer power between Kicker and Hang
pros::ADIDigitalOut Hang('B', false); // Ratchet puller piston in port B to not let the robot fall down
pros::ADIDigitalOut Ctier('D', false); // Back Left wing piston in port D

// PTO to the hang task, this is an int so that it can run the task
int tohangPTO(){

    PTO.set_value(true); // First the PTO piston moves the gear over

    return 0; // makes the task work
}

// PTO to the drivetrain task, this is an int so that it can run the task
int todrivePTO(){

    PTO.set_value(false); // First the PTO piston moves the gear over

    return 0; // makes the task work
}

// Function to make spinning all of the drivetrain motors easier
void spinhang(int hangvolts){

    frontLeft.move_voltage(hangvolts); // spins the front left motor at the set integer of hangvolts
    frontRight.move_voltage(hangvolts); // spins the front right motor at the set integer of hangvolts
    middleLeft.move_voltage(hangvolts); // spins the middle left motor at the set integer of hangvolts
    middleRight.move_voltage(hangvolts); // spins the middle right motor at the set integer of hangvolts
    backLeft.move_voltage(hangvolts); // spins the back left motor at the set integer of hangvolts
    backRight.move_voltage(hangvolts); // spins the back right motor at the set integer of hangvolts

}

// Actual code for the hang. Housed in a task, as it needed to be ran as a task in the past, however, if it is not called as a task in Main.cpp, then it runs as a normal void
int setHang(){
    
    // If the High Hang up button is pressed, and not the shift key, run the code to deploy the high hang
    if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)))){

        Ctier.set_value(true); // activates the C tier piston, releasing the string to go all the way up for the high hang
        Hang.set_value(true); // activates the release for the hang, making the arm go up all the way
        
        // Code to activate the bring the hang down macro
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) and !hangdown){

            hangdown = true; // references the other code that is simmilar for both the C tier and the high hang

        }
        
    }

    // If the C tier hang up button is pressed as well as the shift key, run the code to deploy the c tier hang
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

        Hang.set_value(true); // activates the release for the hang, making the hang go to the height for C tier

        // Code to activate the bring the hang down macro
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) and !hangdown){

            hangdown = true; // references the other code that is simmilar for both the C tier and the high hang

        }


    }

    // When the keys are pressed to make the hang come down, run this common function
    if (hangdown){

        tohangPTO(); // PTO the motorpower from the drivetrain to the hang
        Hang.set_value(false); // Bring the Piston for the hang in, so that it does not become dammaged as the hang moves up/down

        // If the motors are recognized by PROS as not moving, stop the hang
        if (backLeft.is_stopped()){

            spinhang(0); // Stop the drivetrain motors from spinning (set them to 0 volts)
            hangdown = false; // resets the hangdown vairable if it needs to be ran again.

        }

        // If the motors are not recognized by PROS as stopped, run the hang
        else {

            spinhang(12000); // Spin the drivetrain at max voltage

        }

    }

    // makes the task work, as well as the int at the begenning of the function
    return 0;

}