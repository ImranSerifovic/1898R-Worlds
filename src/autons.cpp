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
  chassis.set_drive_exit_conditions(1.5, 0, 3000);
  chassis.set_turn_exit_conditions(2, 0, 5000);
  // Drop intake
  Intake.spin(reverse, 100, voltageUnits::volt); 
  wait(0.2,seconds);
  Intake.spin(forward, 100, voltageUnits::volt);
  // Intake first acorn under barrier 
  chassis.drive_distance(7);
  wait(0.1, seconds);
  Intake.spin(forward, 7, voltageUnits::volt);
  // Back up 
  chassis.drive_distance(-31.5);
  chassis.turn_to_angle(-35, 12, 1, 300, 750);
  BackLeftFlap.set(true);
  chassis.drive_distance(-17, -35, 12, 0, 1, 300, 850);
  // wait(0.2, seconds);
  // chassis.turn_to_angle(-105, 6, 1, 300, 1000);
  chassis.turn_to_angle(-50, 4, 1, 300, 750);
  // chassis.drive_distance(-5, -50, 12, 12, 1, 0, 750);
  BackLeftFlap.set(false);
  // wait(0.1, seconds);
  // return;
  chassis.drive_distance(-50, -90, 12, 12, 1, 300, 1000);
  BackLeftFlap.set(false);
  
  chassis.set_drive_exit_conditions(1.5, 100, 3000);
  chassis.set_turn_exit_conditions(2, 100, 5000);

  // Drive in curve along the match load bar
  chassis.drive_distance(16.6);
  chassis.turn_to_angle(100, 12, 1, 300, 1000);
  flaps.set(true);
  Intake.spin(reverse, 12, voltageUnits::volt);
  // flaps.set(true);
  wait(0.3, seconds);
  chassis.drive_distance(15, 90, 12, 12, 1, 300, 500);
  flaps.set(false);

  chassis.set_drive_exit_conditions(1.5, 0, 3000);
  chassis.set_turn_exit_conditions(2, 0, 5000);

  chassis.drive_distance(-13);
  chassis.turn_to_angle(24, 12, 1, 300, 1000);
  // wait(1.5, seconds);

  Intake.spin(forward, 12, voltageUnits::volt);
  chassis.drive_distance(47.5);
  // Intake.spin(forward, 7, voltageUnits::volt);
  
  wait(0.2, seconds);
  // return;

  chassis.turn_to_angle(155);
  Intake.spin(reverse, 12, voltageUnits::volt);

  chassis.drive_distance(15);

  wait(0.5, seconds);

  // return;

  Intake.spin(forward, 12, voltageUnits::volt);
  chassis.turn_to_angle(45);
  chassis.drive_distance(24);

  flaps.set(true);
  chassis.turn_to_angle(180);
  chassis.drive_distance(40);

}
/*---------------------------------------------------------------------------*/  
/*                            CLOSE SIDE SAFE                                */
/*---------------------------------------------------------------------------*/  
void CloseSideSafe() { 

}
/*---------------------------------------------------------------------------*/  
/*                            CLOSE SIDE RUSH                                */
/*---------------------------------------------------------------------------*/ 

void inertial_read() {
    Controller1.Screen.print(Inertial1.heading());
    Controller1.Screen.print(" ");
}

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
  chassis.drive_distance(-16.7, 160, 10, 12, 1.5, 300, 1200);

  // chassis.drive_distance(-10, 180);
  // Turn so that the back is parallel with the goal 
  // chassis.drive_distance( -20,  0,  12,  8);


  chassis.drive_distance(10);
  // Turn to be parallel with match bar
  chassis.drive_distance(0, 122);
  // Take acorn out of zone 
  BackRightFlap.set(true);

  chassis.drive_distance(16.5);
  // Whip it out of zone
  chassis.drive_distance(3, 60, 12, 12, 1, 300, 1500);
  chassis.drive_distance(5);
  chassis.drive_distance(0, -60);
  // chassis.drive_distance(0, -90);

  BackRightFlap.set(false);
  // Turn back to middle bar and outtake
  chassis.turn_to_angle(97, 12, 1.5, 300, 1000);
  Intake.stop();
  inertial_read();

  wait(0.1, seconds);

  chassis.drive_distance(27, 80);
  Intake.spin(reverse, 100, voltageUnits::volt);
  chassis.drive_distance(10);
  chassis.drive_distance(-3);
}



/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*                               SKILLS AUTOS                                */
/*---------------------------------------------------------------------------*/ 
//devan imma leave this to u idk what u want here 
/*---------------------------------------------------------------------------*/


