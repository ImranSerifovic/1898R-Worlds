#include "vex.h"
/*---------------------------------------------------------------------------*/
/*                            CONSTANTS                                      */
/*---------------------------------------------------------------------------*/
void default_constants(){
  // Constant form: (maxVoltage, kP, kI, kD, startI).


  chassis.set_drive_constants(10, 1.5, 0, 10, 0);


  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Exit condition form: (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}
/*---------------------------------------------------------------------------*/

// PID Test
void pidTest() { 
  chassis.drive_distance(16);
}



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              IN GAME AUTOS                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/  


/*---------------------------------------------------------------------------*/   
/*                            6 BALL SAFE FAR                                */
/*---------------------------------------------------------------------------*/  
void FarSideSafe() {
  // Drop intake
  Intake.spin(reverse, 100, voltageUnits::volt); 
  wait(0.2,seconds);
  Intake.spin(forward, 100, voltageUnits::volt);
  // Intake first acorn under barrier 
  chassis.drive_distance(5);
  // Back up 
  chassis.drive_distance(-43);
  // Drive in curve along the match load bar
}
/*---------------------------------------------------------------------------*/  
/*                            CLOSE SIDE SAFE                                */
/*---------------------------------------------------------------------------*/  
void CloseSideSafe() { 

}
/*---------------------------------------------------------------------------*/  
/*                            CLOSE SIDE RUSH                                */
/*---------------------------------------------------------------------------*/ 
void CloseSideRush() { 
  //Drop Intake
  Intake.spin(reverse, 100, voltageUnits::volt);
  // Hit preload with flap 
  flaps.set(true);
  wait(0.3,seconds);
  flaps.set(false);
  Intake.stop();
  // Drive to get middle acorn
  Intake.spin(forward, 100, voltageUnits::volt);
  chassis.drive_distance(48);
  wait(0.3,seconds);
  Intake.stop();
  // Back up
  chassis.drive_distance(-36);
  // Turn so that the back is parallel with the goal 
  chassis.drive_distance( -20,  0,  12,  8);
  // Hopefully score preload
  chassis.drive_distance(-10);
  // Drive a bit closer to the bar 
  chassis.drive_distance(5);
  // Turn to be parallel with match bar
  chassis.turn_to_angle(135);
  // Take acorn out of zone 
  BackRightFlap.set(true);
  chassis.drive_distance(20);
  // Whip it out of zone
  chassis.turn_to_angle(75);
  BackRightFlap.set(false);
  // Turn back to middle bar and outtake
  chassis.turn_to_angle(90);
  chassis.drive_distance(24);
  Intake.spin(reverse, 100, voltageUnits::volt);
  chassis.drive_distance(10);
  chassis.drive_distance(-1);

}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*                               SKILLS AUTOS                                */
/*---------------------------------------------------------------------------*/ 
//devan imma leave this to u idk what u want here 
/*---------------------------------------------------------------------------*/


