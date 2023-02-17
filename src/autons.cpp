#include "main.h"
#include "headers.hpp"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/117 (around 87% of max speed).  We don't suggest making this 117.
                             // If this is 117 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-11, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-11, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(11);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-11, 117);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .

void roller_side_normal() { // normal auton but with normal indexer
  // what this does is
  // 1. get roller (should be started right in front of roller)
  // 2. go to center
  // 3. shoot disks with single indexer
  //
  // should have one disk in storage and the other in intake

  intake.move_voltage(12000); // do rollers
  chassis.set_drive_pid(2, 100); // move forward while intaking to keep contact with rollers
  
  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-6, 110); // go back
  chassis.wait_drive();

  chassis.set_turn_pid(45.0, 110); // turn 45 deg clockwise so the shooter faces the center of field
                                   // if intake faces center of field then change this to -135 deg
  chassis.set_drive_pid(-30, 110, true, true); // drive to center

  chassis.set_turn_pid(-90.0, 110); // turn toward goal

  flywheel.move_voltage(12000); 

  indexer.set_value(true); // first disk
  pros::delay(500);
  indexer.set_value(false);

  intake.move_voltage(12000); // move up second disk into storage

  pros::delay(2500); // adjust if needed (its in ms)

  indexer.set_value(true); // second disk
  pros::delay(500);
  indexer.set_value(false);
}

void roller_side_single() { // normal auton but with single indexer
  // what this does is
  // 1. get roller (should be started right in front of roller)
  // 2. go to center
  // 3. shoot disks with single indexer
  //
  // should have one disk in storage and the other in intake

  intake.move_voltage(12000); // do roller
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-6, 110); // go back
  chassis.wait_drive();

  chassis.set_turn_pid(45.0, 110); // turn 45 deg clockwise so the shooter faces the center of field
                                   // if intake faces center of field then change this to -135 deg
  chassis.set_drive_pid(-30, 110, true, true); // drive to center

  chassis.set_turn_pid(-45.0, 110); // turn toward goal

  flywheel.move_voltage(12000); 

  indexerSingle.set_value(true); // first disk
  pros::delay(500);
  indexerSingle.set_value(false);

  intake.move_voltage(12000); // move up second disk into storage

  pros::delay(2500); // adjust if needed (its in ms)

  indexerSingle.set_value(true); // second disk
  pros::delay(500);
  indexerSingle.set_value(false);
}

void not_roller_side() { // normal auton but for if you start on the side thats to the left of the roller
  // what this does is
  // 1. get roller (should be started FACING the roller)

  chassis.set_drive_pid(20, 110);
  chassis.wait_drive();
  chassis.set_turn_pid(90.0, 100);
  chassis.wait_drive();
  
  intake.move_voltage(12000); // do rollers
  chassis.set_drive_pid(2, 100); // move forward while intaking to keep contact with rollers

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();
}

void skills() { // programmers skills
  // what this does is
  // 1. get roller (should be started right in front of roller)
  // 2. get second roller
  // 3. shoot disks
  // 4. get other two rollers
  // 5. expand
  // 
  // should have one disk in storage and the other in intake
  //
  // this doesnt try to get another disk because the intake for
  // some reason cant get a disk without doing funny manuevers
  // that can pretty much only be done in user control
  //
  // i really dont think the last two rollers will be possible 
  // without a LOT of trial and error which will take a LOT of
  // time
  // if the last two disks dont work just comment out the 
  // entirety of step 4

  // Step 1
  intake.move_voltage(12000); // do roller 1
  chassis.set_drive_pid(2, 100); // move forward while intaking to keep contact with rollers

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  // Step 2
  chassis.set_drive_pid(-9, 110); // go back
                                   // should be aligned with the second rolelr
  chassis.wait_drive();
  chassis.set_turn_pid(90.0, 110); // should be facing second roller
  chassis.wait_drive();
  chassis.set_drive_pid(11, 110); // engage roller
  chassis.wait_drive();
  
  intake.move_voltage(12000); // do roller 2
  chassis.set_drive_pid(2, 100); // move forward while intaking to keep contact with rollers

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  // Step 3
  chassis.set_drive_pid(-11, 110); // go back
  chassis.wait_drive();
  chassis.set_turn_pid(45.0, 110); // turn with shooter facing center
                                    // if the intake is facing center then change this to -135 deg
  
  chassis.wait_drive();
  
  chassis.set_drive_pid(-23, 110); // drive to center
  chassis.wait_drive();
  chassis.set_turn_pid(-45.0, 110); // turn toward goal
  chassis.wait_drive();

  flywheel.move_voltage(12000);

  pros::delay(750);

  indexerSingle.set_value(true); // first disk
  pros::delay(500);
  indexerSingle.set_value(false);

  intake.move_voltage(-12000); // move up second disk into storage

  pros::delay(2500); // adjust if needed (its in ms)

  indexerSingle.set_value(true); // second disk
  pros::delay(500);
  indexerSingle.set_value(false);

  intake.brake();
  flywheel.brake();

  // Step 4
  chassis.set_turn_pid(-135.0, 110); // turn with intake facing other two rollers
  chassis.wait_drive();
  chassis.set_drive_pid(27, 110);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 110); // doing the right side roller first
  chassis.wait_drive();
  chassis.set_drive_pid(11, 100); // engage roller
  chassis.wait_drive();

  intake.move_voltage(12000); // do roller 3
  chassis.set_drive_pid(2, 100); // move forward while intaking to keep contact with rollers

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 110);
  chassis.wait_drive();
  chassis.set_turn_pid(-180, 110); // doing last roller
  chassis.wait_drive();
  chassis.set_drive_pid(9, 100); // engage roller
  chassis.wait_drive();

  intake.move_voltage(12000); // do roller 4
  chassis.set_drive_pid(2, 100); // move forward while intaking to keep contact with rollers

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 110);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, 110);
  chassis.wait_drive();
  chassis.set_drive_pid(5, 110);

  chassis.wait_drive();

  // Step 5
  expansion.set_value(true);
  // expansion2.set_value(true); // this is if you decide to use a second solenoid for the other piston
}

void test_skills() { // programmers skills but the test version
  // what this does is
  // 1. get roller (should be started right in front of roller)
  // 2. shoot two disks INDIVIDUALLY
  // 3. get second roller
  // 4. move to center while picking up disks
  // 5. shoot picked up disks
  // 6. get line of disks to the front left of robot
  // 7. shoot picked up disks
  // 8. get line of disks on the other
  // 6. head to other two rollers while picking up disks
  // 7. shoot disks
  // 8. get other two rollers
  // 9. expand

  // Step 1: get roller

  intake.move_voltage(12000); // do roller 1
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  // Step 2: shoot two disks

  chassis.set_drive_pid(-9, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(-10, 100);
  chassis.wait_drive();

  flywheel.move_voltage(12000);

  pros::delay(1500);

  indexerSingle.set_value(true);
  pros::delay(5);
  indexerSingle.set_value(false);
  pros::delay(450);
  indexerSingle.set_value(true);
  pros::delay(5);
  indexerSingle.set_value(false);
  pros::delay(450);

  flywheel.brake();

  pros::delay(100);

  // Step 3: get second roller

  chassis.set_turn_pid(90,110);
  chassis.wait_drive();
  chassis.set_drive_pid(8, 120);
  chassis.wait_drive();

  intake.move_voltage(12000); // do roller
  chassis.set_drive_pid(2, 100); // engage roller

  pros::delay(500);

  intake.brake();
  chassis.wait_drive();

  // Step 4: move to center while picking up disks

  chassis.set_drive_pid(-13, 120);
  chassis.wait_drive();
  chassis.set_turn_pid(225, 120);
  chassis.wait_drive();
  
  intake.move_voltage(12000);

  chassis.set_drive_pid(21.5, 85);
  chassis.wait_drive();
  chassis.set_turn_pid(135, 100);
  chassis.wait_drive();

  pros::delay(1000);
  
  intake.brake();

  indexerSingle.set_value(true);
  pros::delay(5);
  indexerSingle.set_value(false);
  pros::delay(450);
  indexerSingle.set_value(true);
  pros::delay(5);
  indexerSingle.set_value(false);
  pros::delay(450);
}