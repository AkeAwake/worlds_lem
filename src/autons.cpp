// Includes any libraries added, and making sure that the code is implemented correctly
#include "main.h"
#include "pros/imu.h"
#include "pros/screen.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"

ASSET(BackwardsPushIntoGoal_txt);
ASSET(SecondPushInSixball_txt);
ASSET(AwayFromGoal_txt);
ASSET(RushSixIntakeBall_txt);
ASSET(PushBallsIntoGoal_txt);
ASSET(FirstPush_txt);
ASSET(AroundGoalToMatchloadbar_txt);
ASSET(NonawpAroundGoalToMatchloadbar_txt);
ASSET(RushToMiddle_txt);
ASSET(kachigaaway_txt);
ASSET(kachigaaway2_txt);
ASSET(kachiga_txt);
ASSET(skillspush1_txt);
ASSET(skillspush2_txt);
ASSET(skillspush3_txt);
ASSET(skillspush4_txt);
ASSET(skillspush5_txt);
ASSET(skillspush6_txt);
ASSET(skillspush7_txt);
ASSET(hehe_txt);

// sets the pistons to be used in the autonomous
pros::ADIDigitalOut lWing('E', false); // Front Left Wing in port E
pros::ADIDigitalOut rWing('C', false); // Front Right Wing in port C
pros::ADIDigitalOut blWing('D', false); // Back Left Wing in port D
pros::ADIDigitalOut brWing('A', false); // Back Right Wing in port A
pros::ADIDigitalOut hangratchet('B', false); // Ratchet puller in port B
pros::ADIDigitalOut autoPTO('H', false); // PTO between hang and Kicker in port H

// Wing Tasks to be used inside of autonomous to simplify code
    
    // Bring both the front wings in
    void wingintask(){

        rWing.set_value(false);
        lWing.set_value(false);

    }

    // Push both the front wings out
    void wingouttask(){

        rWing.set_value(true);
        lWing.set_value(true);

    }

    // Bring both of the back wings in
    void backwingintask(){

        brWing.set_value(false);
        blWing.set_value(false);

    }

    // Push both of the back wings out
    void backwingouttask(){

        brWing.set_value(true);
        blWing.set_value(true);

    }

    // Push the Front Left Wing out
    void leftwingouttask(){

        lWing.set_value(true);

    }

    // Bring the Front Left Wing in
    void leftwingintask(){

        lWing.set_value(false);

    }

    // Push the Front Right Wing out
    void rightwingouttask(){

        rWing.set_value(true);

    }

    // Bring the Front Right Wing in
    void rightwingintask(){

        rWing.set_value(false);

    }

    // Push the Back Left Wing out
    void backleftwingouttask(){

        blWing.set_value(true);

    }

    // Bring the Back Left Wing out
    void backleftwingintask(){

        blWing.set_value(false);

    }

    // Push the Back Right Wing out
    void backrightwingouttask(){

        brWing.set_value(true);

    }

    // Bring the Back Right Wing in
    void backrightwingintask(){

        brWing.set_value(false);

    }

    // Makes the Intake deploy for autonomous, made an int for a task
    int intakedeploy(){
        
        // whatever dylan cooks

        // makes the task work
        return 0;
    }
    
    // For the rush code we want the movement to be the first decleration during the auton, so we run everything else in a task
    int start(){

        // Turns the intake on, and brings in the right wing
        Intake1 = 127;
        Intake2 = 127;
        pros::delay(300);
        rWing.set_value(false);

        // makes the task work
        return 0;

    }

    void nearsafe(){


        
    }

    void nearelims(){




    }

    void nearrush(){




    }

    void sixballtouch(){



    }

    void sevenballmid(){



    }

    void sevenballbar(){


        
    }

    // defines the rush sixball
    void rushsixball(){

        chassis.setPose(-45.552, 55.817, 146.45); // sets the position to 91x, 154y, and 179deg
        chassis.follow(RushToMiddle_txt, 15, 7800, true, true);
        rightwingouttask();
        autohang();
        intakeON();
        pros::delay(150);
        rightwingintask();
        //autotokickerpto();
        chassis.waitUntilDone();
        chassis.turnTo(-43.529, 2.46, 900 , true, 127, true);
        chassis.waitUntilDone();
        chassis.moveToPoint(-43.529, 2.46, 2000, true, 127, true); // turns without boomerang to 12x 12y
        pros::delay(300);
        intakeREVERSE();
        wingouttask();
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.moveToPoint(-32.013, 2.46, 2000, false, 127, false); // turns without boomerang to 12x 12y
        wingintask();
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.turnTo(-13.46, 28.175, 900 , true, 127, true);
        chassis.waitUntilDone();
        intakeON();
        chassis.moveToPoint(-13.46, 25.175, 2000, true, 127, false); // turns without boomerang to 12x 12y
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.turnTo(-109.751, 131.688, 500 , true, 127, true);
        chassis.waitUntilDone();
        chassis.follow(RushSixIntakeBall_txt, 15, 5000, true, true);
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.turnTo(-58.956, 27.261, 500, true, 127, true);
        chassis.waitUntilDone();
        intakeREVERSE();
        pros::delay(500);
        chassis.turnTo(-7.021, 62.232, 900, true, 127, true);
        chassis.waitUntilDone();
        intakeON();
        chassis.moveToPoint(-11.021, 62.232, 1900, true, 127, true); // turns without boomerang to 12x 12y
        chassis.waitUntilDone(); // waits for the movement to be done
        pros::delay(300);
        chassis.follow(PushBallsIntoGoal_txt, 15, 2400, false, true);
        pros::delay(700);
        backleftwingouttask();
        backrightwingouttask();
        pros::delay(400);
        backleftwingintask();
        chassis.waitUntilDone();
        chassis.moveToPoint(-64.128, 25, 1900, false, 127, false);
        chassis.waitUntilDone();
        chassis.moveToPoint(-56, 42, 3000, true, 127, false);
        backrightwingintask();
        chassis.waitUntilDone();
        chassis.turnTo(-75, -34, 700, true, 127, true);
        chassis.waitUntilDone();
        chassis.turnTo(-75, -12, 700, true, 127, true);
        chassis.waitUntilDone();
        intakeREVERSE();
        chassis.moveToPoint(-69, -12, 900, true, 127, false);
        chassis.waitUntilDone();
        chassis.moveToPoint(-69, 42, 600, false, 127, false);
        chassis.waitUntilDone();
        intakeOFF();

    }

    // defines the safe sixball
    void normalsixball(){

    }

    // defines the rush that also shoots the preload into the goal
    void awprush(){

        chassis.setPose(40.841, 59.26, 197.256); // sets the position to 109x, 151y, and 199deg
        //pros::Task elimsrushstart(start);
        intakeON();
        chassis.moveToPoint(27, 10.7, 1500, true, 127, true); // turns without boomerang to 12x 12y
        autohang();
        chassis.waitUntilDone();
        //autotokickerpto();
        chassis.turnTo(6, 11.181, 800 , true, 127, false);
        leftwingouttask();
        chassis.waitUntilDone();
        chassis.moveToPoint(6, 11.181, 1500, true, 127, true); // turns without boomerang to 12x 12y
        pros::delay(300);
        intakeREVERSE();
        chassis.waitUntilDone();
        pros::delay(200);
        leftwingintask();
        intakeOFF();
        chassis.turnTo(44, 50, 500 , false, 127, true);
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.moveToPoint(44, 50, 1900, false, 127, true); // turns without boomerang to 12x 12y
        chassis.waitUntilDone();
        backleftwingouttask();
        pros::delay(200);
        chassis.turnTo(13.53, 30.181, 700 , false, 127, true);
        chassis.waitUntilDone();
        backleftwingintask();
        chassis.turnTo(8, 73, 900 , true, 127, true);
        chassis.waitUntilDone();
        intakeREVERSE();
        chassis.moveToPoint(9.2, 65, 1500, true, 127 , true); // moves to the first ball with boomerang
        pros::delay(700);
        wingouttask();
        chassis.waitUntilDone();

    }

    // defines the rush nearside that dosent shoot the preload
    void elimsrush(){

        chassis.setPose(40.841, 59.26, 197.256); // sets the position to 109x, 151y, and 199deg
        //pros::Task elimsrushstart(start);
        intakeON();
        chassis.moveToPoint(27, 10.7, 1500, true, 127, true); // turns without boomerang to 12x 12y
        autohang();
        chassis.waitUntilDone();
        //autotokickerpto();
        chassis.turnTo(6, 11.181, 800 , true, 127, false);
        leftwingouttask();
        chassis.waitUntilDone();
        chassis.moveToPoint(6, 11.181, 1500, true, 127, true); // turns without boomerang to 12x 12y
        pros::delay(300);
        intakeREVERSE();
        chassis.waitUntilDone();
        pros::delay(200);
        leftwingintask();
        intakeOFF();
        chassis.turnTo(44, 50, 500 , false, 127, true);
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.moveToPoint(44, 50, 1900, false, 127, true); // turns without boomerang to 12x 12y
        chassis.waitUntilDone();
        backleftwingouttask();
        pros::delay(200);
        chassis.turnTo(13.53, 30.181, 700 , false, 127, true);
        chassis.waitUntilDone();
        backleftwingintask();
        chassis.turnTo(8, 73, 900 , true, 127, true);
        chassis.waitUntilDone();
        intakeREVERSE();
        chassis.moveToPoint(9.2, 65, 1500, true, 127 , true); // moves to the first ball with boomerang
        pros::delay(700);
        wingouttask();
        chassis.waitUntilDone();
        chassis.moveToPoint(45, 52, 1900, false, 127, true); // turns without boomerang to 12x 12y
        chassis.waitUntilDone();
        intakeOFF();
        backrightwingouttask();
    }

    void skills(){

        chassis.setPose(-46.464, -58.488, 324.2); // sets the position to 109x, 151y, and 199deg
        autohang();
        chassis.follow(FirstPush_txt, 10, 1600, true, true);
        pros::delay(150);
        intakeREVERSE();
        chassis.waitUntilDone(); // waits for the movement to be done
        intakeOFF();
        chassis.moveToPoint(-58.389, -40.141, 1800, false, 127, false);
        chassis.waitUntilDone();
        chassis.turnTo(46.6, 12, 500 , true, 127, true);
        shoottask();
        chassis.waitUntilDone();
        backrightwingouttask();
        chassis.moveToPoint(-61.2, -41.4, 1800, false, 127, false);
        chassis.waitUntilDone();       
        chassis.turnTo(46.6, 12, 900 , true, 127, true);
        chassis.waitUntilDone();
        pros::delay(24000);
        pros::delay(500);
        Kicker = 0;
        Kicker2 = 0;
        chassis.setPose(chassis.getPose());
        backrightwingintask();
        intakeREVERSE();
        pros::delay(500);
        chassis.moveToPose(0, -32.6, 90, 1900, {}, true);
        pros::delay(500);
        leftwingouttask();
        chassis.waitUntilDone();
        leftwingintask();
        chassis.moveToPoint(-15, -32.6, 900, false, 127, true);
        chassis.waitUntilDone();
        chassis.turnTo(-23, 36, 900 , true, 127, true);
        chassis.waitUntilDone();
        rightwingouttask();
        chassis.moveToPoint(-23, 36, 1900, true, 127, true);
        chassis.waitUntilDone();
        //chassis.follow(kachiga_txt, 7, 2500, true, true);
        //chassis.waitUntilDone();
        intakeOFF();
        rightwingintask();
        chassis.turnTo(-25.45, 22.691, 900 , false, 127, true);
        chassis.waitUntilDone();
        chassis.follow(kachigaaway_txt, 8, 1600, false, true);
        chassis.follow(kachigaaway2_txt, 7, 1600, false, true);
        chassis.follow(skillspush1_txt, 15, 2500, false, true);
        pros::delay(1200);
        backleftwingouttask();
        chassis.waitUntilDone();
        chassis.follow(hehe_txt, 15, 2500, false, true);
        backleftwingintask();
        chassis.moveToPoint(56.31, 47.808, 900, true, 127, true);
        chassis.waitUntilDone();
        chassis.turnTo(22, 0.7, 900 , true, 127, true);
        chassis.waitUntilDone();
        chassis.moveToPoint(22, 0.7, 2500, true, 127, true);
        chassis.waitUntilDone();
        chassis.turnTo(60.397, -2.103, 900 , true, 127, true);
        chassis.waitUntilDone();
        wingouttask();
        chassis.moveToPoint(60.397, -2.103, 2500, true, 127, true);
        chassis.waitUntilDone();
        wingintask();
        chassis.follow(skillspush3_txt, 9, 3500, false, true);
        chassis.waitUntilDone();
        chassis.turnTo(49.236, -21.726, 900 , true, 127, true);
        chassis.waitUntilDone();
        wingouttask();
        chassis.follow(skillspush4_txt, 9, 3000, true, true);
        chassis.waitUntilDone();
        wingintask();
        chassis.moveToPoint(47.316, -16.288, 2500, false, 127, true);
        chassis.waitUntilDone();
        chassis.turnTo(70.146, -78.494, 900 , true, 127, true);
        chassis.waitUntilDone();
        chassis.follow(skillspush5_txt, 9, 3500, true, true);
        chassis.follow(skillspush6_txt, 9, 3000, true, true);
        leftwingouttask();
        chassis.waitUntilDone();
        chassis.moveToPoint(73.784, -48.596, 2500, false, 127, true);
        chassis.waitUntilDone();
        chassis.moveToPoint(73.784, -24.925, 1500, true, 127, true);
        chassis.waitUntilDone();
        //out and in 6
        leftwingintask();
        chassis.follow(skillspush7_txt, 9, 3500, false, true);
        pros::delay(600);
        //horizontal hang up
        chassis.waitUntilDone();
        chassis.turnTo(20.5, -67.5, 900 , true, 127, true);
        chassis.waitUntilDone();
        chassis.moveToPose(17.5, -67.5, 270, 1900, {}, true);
        chassis.waitUntilDone();
        //hang down

        
        



    }

    void drivermacro(){

        chassis.setPose(-46.464, -58.488, 324.2); // sets the position to 109x, 151y, and 199deg
        autohang();
        chassis.follow(FirstPush_txt, 10, 1600, true, true);
        pros::delay(150);
        intakeREVERSE();
        chassis.waitUntilDone(); // waits for the movement to be done
        intakeOFF();
        chassis.moveToPoint(-58.389, -40.141, 1800, false, 127, false);
        chassis.waitUntilDone();
        chassis.turnTo(46.6, 8, 500 , true, 127, true);
        shoottask();
        chassis.waitUntilDone();
        backrightwingouttask();
        chassis.moveToPoint(-61.2, -41.4, 1800, false, 127, false);
        chassis.waitUntilDone();       
        chassis.turnTo(46.6, 8, 900 , true, 127, true);
        chassis.waitUntilDone();
        pros::delay(24000);
        pros::delay(500);
        Kicker = 0;
        Kicker2 = 0;

    }

    // test auton
    void test(){

        chassis.setPose(0, 0, 0); // sets the position to 0x, 0y, and 0deg
        chassis.moveToPoint(0, 12, 10000, true, 127, true); // turns without boomerang to 12x 12y
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.moveToPoint(0, 0, 10000, false, 127, false); // goes backwards to 0x 0y
        chassis.waitUntilDone(); // waits for the movement to be done

        pros::delay(99999); // waits as this is the only auto that needs to be done
        
        // begenning of the rush sixball
        chassis.setPose(35.801, -59.472, 346.983); // sets the starting position and heading of the robot
        chassis.moveToPose(23.645, -0.294, 346.983, 1800, {}, true); // moves to the first ball with boomerang
        chassis.waitUntilDone(); // waits for the movement to be done
        chassis.moveToPose(35.801, -59.472, 346.983, 1800, {false}, true); // moves back to the start
        chassis.waitUntilDone(); // waits for the movement to be done

        // excess code

        //chassis.moveToPose(0, 0, 0, 10000, {false}, false);
        //chassis.waitUntilDone();
        
        /*chassis.setPose(0, 0, 0);
        chassis.moveToPoint(12, 12, 10000, true, 127, true);
        chassis.waitUntilDone();
        chassis.moveToPoint(0, 0, 10000, false, 127, false);
        chassis.waitUntilDone();*/
        //chassis.turnTo(10, 0, 1000, true, 127, true);
        //chassis.waitUntilDone();
        //chassis.turnTo(0, 10, 1000, true, 127, true);
        //chassis.waitUntilDone();
        //chassis.turnTo(-23.201, -0.512, 1000, false, 127);
        /*chassis.setPose(-36.618, 62.515, 180);
        rWing.set_value(true);
        pros::Task startingtask(start);
        chassis.moveTo(-5.729, 3.232, 1600, 127, true);
        Intake1 = 0;
        Intake2 = 0;
        chassis.turnTo(-47.851, 3.232, 400, false, 127, true);
        rWing.set_value(true);
        Intake1 = -127;
        Intake2 = -127;
        // -36.114
        chassis.moveTo(-100, 3.232, 800, 127, true);
        chassis.setPose(chassis.getPose());
        rWing.set_value(false);
        Intake1 = 0;
        Intake2 = 0;
        chassis.moveTo(-30.378, 0.112, 500, 127, true);
        Intake1 = 127;
        Intake2 = 127;
        chassis.turnTo(-8.537, 23.201, 300, false, 127, true);
        chassis.moveTo(-8.537, 23.201, 900, 127, true);
        chassis.turnTo(-55.339, 23.201, 500, false, 127, true);
        //chassis.setPose(-55.339, 23.201, 270);
        chassis.setPose(chassis.getPose());
        chassis.follow("2.txt", 1100, 15, false, 127, true);
        rWing.set_value(true);
        chassis.turnTo(-70.628, 48.787, 300, false, 127, true);
        //chassis.setPose(-70.628, 48.787, 270);
        chassis.setPose(chassis.getPose());
        Intake1 = -127;
        Intake2 = -127;
        chassis.follow("testpath.txt", 1100, 10, false, 127, true);
        rWing.set_value(false);
        chassis.moveTo(-62.515, -5.504, 500, 127, true);
        chassis.setPose(chassis.getPose());
        Intake1 = 0;
        Intake2 = 0;
        chassis.moveTo(-62.515, 30.378, 500, 127, true);
        chassis.turnTo(-40.362, 45.667, 300, false, 127, true);*/
        //chassis.setPose(-62.515, 30.378, 55);
        //Intake1 = 127;
        //Intake2 = 127;
        //chassis.follow("to_elevate.txt", 1100, 10, false, true);
        //pros::lcd::print(4, "pure pursuit finished!");


    }