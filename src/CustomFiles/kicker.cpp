// Grabs all of the other code in any other files that could be used in this file
#include "main.h"

// Sets the boolean toggle for the Kicker
bool kickerToggle = false; // If this is on, the kicker should be on
bool offToggle = true; // If this is off, the motors for kicker should be off. This is the opposite of KickerToggle, and is set only by the button for kicker
bool hangoffToggle = true; // If this is off, the motors for the hang should be off. This is set only by the hang, as to not mess up the vairable for the Kicker
bool pressedKickerToggle = false; // Intermediate toggle function to know if the button has been pressed

// sets the boolean toggle for the hang
bool verthang = false; // If this is on, the verthang code macro runs
bool horizontalhang = false; // If this is on, the horizontalhang code macro runs
bool bringdown = false; // If this is on, the code brings the hang down back to the starting position

// sets the booleans for knowing if the vert, horizontal, or bringing the arm down code has been run
bool pressedVert = false; // If this is on, the robot has already ran the verthang macro
bool pressedHorizontal = false; // If this is on, the robot has already ran the horizontal hang macro
bool pressedDown = false; // If this is on, the robot has already ran the bringing the arm down macro

// sets the booleans for knowing if the robot has passed the heights for the hang
bool pastv = false; // If this is on, the hang arm should be all the way up for vertical hang
bool pasth = false; // If this is on, the hang arm should be about halfway up to be primed for horizontal hang
bool pastvdown = false; // If this is on, the arm has been brought down to the begenning for vert hang
bool pasthdown = false; // If this is on, the arm has been brought down to the begenning for horizontal hang

// Sets the position function of the 11 watt motor using the built-in encoder
float pose = 0; // MUST BE A FLOAT. A float has a decimal place and an int dosent. The motor encoders use decimals so it needs to be an int.

// Setting up the pistons for the code to be used
pros::ADIDigitalOut PTO('H', false); // PTO piston in port H to transfer power between Kicker and Hang
pros::ADIDigitalOut Ratchet('B', false); // Ratchet puller piston in port B to not let the robot fall down
pros::ADIDigitalOut leftmatchloadWing('D', false); // Back Left wing piston in port D
pros::ADIDigitalOut rightmatchloadWing('A', false); // Back right wing piston in port A

// PTO to the kicker task, this is an int so that it can run the task
int tokickerPTO(){

    PTO.set_value(true); // First the PTO piston moves the gear over

    // If the gear gets stuck, the motors spin in the opposite direction to make it run
    // Hang goes up, or stalls the kicker
    // Kicker = 127; 
    // Kicker2 = 127;

    // pros::delay(200);

    // Kicker = 0;
    // Kicker2 = 0;

    // Makes the task work
    return 0;
}

// PTO to the hang task, this is an int so that it can run the task
int tohangPTO(){

    PTO.set_value(false); // First the PTO piston moves the gear over

    // If the gear gets stuck, the motors spin in the opposite direction to make it run
    // Hang goes down, or shoots the kicker
    // Kicker = 127;
    // Kicker2 = 127;

    // pros::delay(200);

    // Kicker = 0;
    // Kicker2 = 0;

    // Makes the task work
    return 0;
}

// Actual code for the kicker. Housed in a task, as it needed to be ran as a task in the past, however, if it is not called as a task in Main.cpp, then it runs as a normal void
int setKicker(){

    // Right at the begenning of the program, the position of the 11 watt motor is being monitored while driver control is going on. This is because the funciton is being ran in a while true
    pose = Kicker.get_position();

    //Ratchet.set_value(true); // The ratchet is set to not stop the hang, as it could be important for the gear to move before hanging

    // The hang and the kicker are set to stop at the begenning of the program, as it is the most important for it to stop first.
    // offtoggle from kicker and hangofftoggle from hang must both be true to stop the motors
    if (offToggle and hangoffToggle) {

        Kicker = 0; // sets the motors to 0 volts, or not moving
        Kicker2 = 0; // sets the motors to 0 volts, or not moving

        leftmatchloadWing.set_value(false); // brings in the back left wing, as we are no longer matchloading
        rightmatchloadWing.set_value(false); // brings in the back right wing, as we are no longer matchloading

    }

    //If the Kicker button has been pressed, and it has not been pressed yet, switch the states for the kickertoggle, and run the PTO
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and !pressedKickerToggle) {

        kickerToggle = !kickerToggle; // the kicker needs to be switched, if it is on it is off, if it is off, it is on
        offToggle = !offToggle; // the offtoggle needs to be switched it is opposite of kickerToggle
        pressedKickerToggle = true; // the button has now been pressed once
        tokickerPTO(); // PTO to kicker
        leftmatchloadWing.set_value(true); // set the wings to be true, as we are matchloading
        rightmatchloadWing.set_value(true); // set the wings to be true, as we are matchloading

    }

    // If the Kicker button has been released, reset the toggle
    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        
        pressedKickerToggle = false; // the button has been released, be ready for the next press

    }

    // If the toggle for the kicker is on, and the verthang, horizontalhang, and the bringdown macro are off, run the code to shoot the kicker
    if (kickerToggle and !verthang and !horizontalhang and !bringdown){

        // Set the motors to coast, we dont want them to burn out easily, and if they are holding, the catapult will not work
        Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

        // Put out the wings, so it is easier for lucas
        leftmatchloadWing.set_value(true);
        rightmatchloadWing.set_value(true);
        Kicker = 103; // spin the motors
        Kicker2 = 103;

        // If the kicker is running, reset the vairables for the hang, as we would like to run it multiple times
        pastv = false;
        pasth = false;
        pastvdown = false;
        pasthdown = false;
        pressedVert = false;
        pressedHorizontal = false;
        pressedDown = false;

    }
    
    // If the Shiftkey, and the intake button are on, turn on the verthang macro
    else if (!kickerToggle and (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) and !verthang and !horizontalhang and !bringdown){

        // preparing to run the hang macro
        tohangPTO(); // PTOing to the hang
        Ratchet.set_value(false); // sets the ratchet to not be on, so that the verthang can go up
        Kicker.tare_position(); // resets the 11 watt kicker motor, so shooting the kicker dosent mess up the code

        // resets the vairables to ensure the hang works, and nothing breaks
        hangoffToggle = false;
        pastvdown = false;
        pastv = false;

        // activate macro and know that it is running
        verthang = true;
        pressedVert = true;
        
    } 
    
    // If the key is being pressed, and the other hangs are not currently active, run the horizontalhang
    else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) and !verthang and !horizontalhang and !bringdown){

        // preparing to run the hang macro
        tohangPTO(); // PTOing to the hang
        Ratchet.set_value(false); // sets the ratchet to not be on, so that the horizontalhang can go up
        Kicker.tare_position(); // resets the 11 watt kicker motor, so shooting the kicker dosent mess up the code
        

        // resets the vairables to ensure the hang works, and nothing breaks
        hangoffToggle = false;
        pasthdown = false;
        pasth = false;

        // activate the macro and know that it is running
        horizontalhang = true;
        pressedHorizontal = true;

    }
    
    // If one of the hangs is active and B is pressed, run the bring down macro
    else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) and !bringdown){
        
        // First turn the ratchet on so that the robot says up
        Ratchet.set_value(true);

        // Kicker = 127;
        // Kicker = 127;

        // pros::delay(1000);

        // Kicker = 0;
        // Kicker = 0;
        
        // reset the vairables
        hangoffToggle = false;

        // activate the macro and know that it is running
        bringdown = true;
        pressedDown = true;

    }
    
    // If the hang is ran back to back, the vairables need to be reset, and so this code ensures that all of the vairables are reset before running the code
    else if (!kickerToggle and (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) and controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) and pressedVert){

        // Reset the vairables
        pastv = false;
        pasth = false;
        pastvdown = false;
        pasthdown = false;
        pressedVert = false;
        pressedHorizontal = false;
        pressedDown = false;

        tohangPTO(); // pto to hang
        Ratchet.set_value(false); // make sure ratchet is not enabled
        //Kicker.tare_position(); // reset the position
        

        // run the macro
        hangoffToggle = false;
        verthang = true;
        
    }
    
    // If the hang is ran back to back, the vairables need to be reset, and so this code ensures that all of the vairables are reset before running the code
    else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) and pressedHorizontal){

        // Reset the vairables
        pastv = false;
        pasth = false;
        pastvdown = false;
        pasthdown = false;
        pressedVert = false;
        pressedHorizontal = false;
        pressedDown = false;

        tohangPTO(); // pto to hang
        Ratchet.set_value(false); // make sure the ratchet is not enabled
        Kicker.tare_position(); // reset the position

        // run the macro
        hangoffToggle = false;
        horizontalhang = true;

    }
    
    // If the hang is ran back to back, the vairables need to be reset, and so this code ensures that all of the vairables are reset before running the code
    else if (!kickerToggle and controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) and pressedDown){
        
        // reset the vairables
        pastvdown = false;
        pasthdown = false;
        
        Ratchet.set_value(true); // enable the ratchet

        // Kicker = 127;
        // Kicker = 127;

        // pros::delay(1000);

        // Kicker = 0;
        // Kicker = 0;

        // run the macro
        hangoffToggle = false;
        bringdown = true;
    
    }

    // If the verthang macro is on, heres what to run
    if (verthang){

        // set the hang to hold its position so that it does not fall back down under the pressure of the hang
        Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        // If the position of the hang is past, or at where it needs to be, stop the motors
        // 6550
        if ((pose >= 12100)){

            pastv = true; // makes the program know the position is past where it needs to be
            
            // Ensures that the motors are holding, as the motors are defined to coast in other areas of the program
            Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            
            // stops the motors
            Kicker = 0;
            Kicker2 = 0;

            hangoffToggle = true;

        }
        
        // If the hang hasnt past the position, spin the motors
        // 6550
        if((pose < 12100) and !pastv){

            Kicker.move_voltage(12700); // move max voltage
            Kicker2.move_voltage(12700); // move max voltage

        }
        
        // If during the verthang, if bringdown macro is run and it is all the way up, run this code
        if (bringdown and pastv){

            // If the position is close to the where it started, stop the motors
            if ((pose < 1000)){

                pastvdown = true; // makes the program know that the arm is all the way down
                
                // Set the motors to coast, as you dont want them to stall at the top, as well as if it falls then the hang could be ran again
                Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                
                Kicker = 0; // stop the motors
                Kicker2 = 0; // stop the motors

                // reset the vairables
                hangoffToggle = true; // ensure the program has stopped referencing the motors to stop at the top of this file
                verthang = false;
                bringdown = false;
                

            }
            
            // If the position is not almost all the way down, make the motors move up
            if ((pose > 1000) and !pastvdown){

                Ratchet.set_value(true);
                
                // Set the motors to hold, as they are defined to coast at other parts of the project
                Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
                Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
                
                Kicker.move_voltage(-12700); // Sets the motors to move at the max speed
                Kicker2.move_voltage(-12700); // Set the motors to move at the max speed

            }

        }
        

    }

    // If the horizontal hang macro is run, here is the code
    if (horizontalhang){

        // First set the code to hold the motor, as in other places the motor is set to coast
        Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        // If the hang is further back than this value, stop the motors
        if((pose >= 6300)){

            pasth = true; // Set the vairable to let the code know the arm is as far back as it needs to be
            
            // set the motors to hold, as in other places they are set to coast
            Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            // stop the motors
            Kicker = 0;
            Kicker2 = 0;

            hangoffToggle = true; // ensure that the motors are off by checking at the first loop at the top of the file

        }
        
        // If the arm is not all the way up, continue to spin the motors
        if((pose < 6300) and !pasth){

            Kicker.move_voltage(12700); // spin the motor at max voltage
            Kicker2.move_voltage(12700); // spin the motor at max voltage

        }

        // If during the horizontal hang, the macro is ran to bring the arm down, run it here
        if (bringdown and pasth){

            // If the arm is near being all the way down, stop the motors
            if ((pose < 5)){

                pasthdown = true; // let the code know that the arm is in the bottom state
                
                // sets the motors to coast so that when it is all the way down the motors do not stall if they get stuck on something
                Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
                Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

                // Stop the motors by sending 0 volts
                Kicker = 0;
                Kicker2 = 0;

                // let the code double check that the motors are off
                hangoffToggle = true;

                // reset the vairables for the next time that the code is ran
                horizontalhang = false;
                bringdown = false;

            }
            
            // If the arm is not all the way down yet, spin the motors
            if ((pose > 5) and !pasthdown){

                Ratchet.set_value(true);
                
                // Set the motor state to hold its position, as they are set to coast in other spots
                Kicker.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
                Kicker2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

                // Set the motors to spin as fast as they can
                Kicker.move_voltage(-12700);
                Kicker2.move_voltage(-12700);

            }

        }

    }

    // makes the task work, as well as the int at the begenning of the function
    return 0;

}

// Helper function for autonomous as well as testing
void KickerON(){

    Kicker = 127;
    Kicker2 = 127;

}

// Helper function for autonomous as well as testing
void KickerOFF(){

    Kicker = 0;
    Kicker2 = 0;

}