#include "vex.h"
/*---------------------------------------------------------------------------*/
/*                            CONSTANTS                                      */
/*---------------------------------------------------------------------------*/
void default_constants(){
  // Constant form: (maxVoltage, kP, kI, kD, startI).


  chassis.set_drive_constants(12, 1.3, 0, 1, 0);
  chassis.set_turn_constants(12, .12, 1, .7, 0);

  chassis.set_heading_constants(12, .2, 0, 2, 0);
  
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Exit condition form: (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 3000);
  chassis.set_turn_exit_conditions(2, 300, 5000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}
/*---------------------------------------------------------------------------*/

// PID Test
void pidTest() { 
  Controller1.Screen.print(Inertial1.heading());
  Controller1.Screen.print(" ");
  chassis.drive_distance(15, 90);
  Controller1.Screen.print(Inertial1.heading());
  Controller1.Screen.print(" ");
  chassis.drive_distance(1);
    chassis.drive_distance(0, 180);
  chassis.drive_distance(1);

  // chassis.turn_to_angle(180);
  // Controller1.Screen.print(Inertial1.heading());
  Controller1.Screen.print(" ");
  chassis.drive_distance(15, 270);
    chassis.drive_distance(1);
  chassis.drive_distance(0, 0);
    chassis.drive_distance(1);

  // chassis.turn_to_angle(0);
   Controller1.Screen.print(Inertial1.heading());
  // chassis.turn_to_angle(180);
  // Controller1.Screen.print(Inertial1.angle());

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
  // Drive in curve along the match load ba
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
  chassis.set_drive_exit_conditions(1.5, 100, 3000);
  chassis.drive_distance(50.5);
  chassis.set_drive_exit_conditions(1.5, 300, 3000);



  // wait(0.3,seconds);
  Intake.spin(forward, 7, voltageUnits::volt);

  // Back up
  chassis.drive_distance(-37);
  chassis.drive_distance(-8, 90, 12, 8);
  chassis.drive_distance(-14);
  chassis.drive_distance(-18, 160, 10, 12, 1.5, 300, 1200);

  // chassis.drive_distance(-10, 180);
  // Turn so that the back is parallel with the goal 
  // chassis.drive_distance( -20,  0,  12,  8);


  chassis.drive_distance(10);
  // Turn to be parallel with match bar
  chassis.drive_distance(0, 120);
  // Take acorn out of zone 
  BackRightFlap.set(true);

  chassis.drive_distance(21.5);
  // Whip it out of zone
  chassis.drive_distance(10, -90);
  BackRightFlap.set(false);
  // Turn back to middle bar and outtake
  wait(3, seconds);
  chassis.drive_distance(0, 76);
  wait(0.1, seconds);

  chassis.drive_distance(27);
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


