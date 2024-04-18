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
  chassis.drive_distance(-29.8, 0, 10, 12);

  // all descore mvmts
  chassis.turn_to_angle(-44, 12, 1, 0, 750);
  BackLeftFlap.set(true);
  chassis.drive_distance(-9, -44, 12, 0, 1, 0, 850);
  chassis.drive_distance(-10, -90);
  chassis.turn_to_angle(-50, 4, 1, 0, 400);

  // score acorns
  BackLeftFlap.set(false);
  chassis.drive_distance(-50, -90, 12, 12, 1, 0, 1000);
  
  // 100 msecs is lowest these exit conditions should go
  chassis.set_drive_exit_conditions(1.5, 100, 3000);
  chassis.set_turn_exit_conditions(2, 100, 5000);

  // score acorn in intake
  chassis.drive_distance(14); 
  chassis.turn_to_angle(100, 12, 1, 100, 1000);
  Intake.spin(reverse, 12, voltageUnits::volt);
  wait(0.3, seconds);
  chassis.drive_distance(15, 90, 12, 12, 1, 100, 550);


  chassis.set_drive_exit_conditions(1.5, 0, 3000);
  chassis.set_turn_exit_conditions(2, 0, 5000);


  // aim at and intake 1st mid bar acorn
  chassis.drive_distance(-13);
  chassis.turn_to_angle(24.5, 12, 1, 0, 800);
  Intake.spin(forward, 12, voltageUnits::volt);
  chassis.drive_distance(48, 25);  
  wait(0.2, seconds);

  // outtake intaked acorn
  chassis.turn_to_angle(143.7, 12, 1.5, 0, 650);
  Intake.spin(reverse, 12, voltageUnits::volt);
  chassis.drive_distance(16);
  wait(0.48, seconds);

  // get 2nd acorn
  chassis.turn_to_angle(41, 12, 1.5, 0, 650);
  Intake.spin(forward, 12, voltageUnits::volt);
  chassis.drive_distance(22.5, 41);
  wait(0.1, seconds);

  //turn, outtake, and score!
  chassis.turn_to_angle(183, 6, 1.5, 0, 900);
  flaps.set(true);
  Intake.spin(reverse, 12, voltageUnits::volt);
  wait(0.6, seconds);
  chassis.drive_distance(40, 183, 12, 12, 1, 0, 700);
  chassis.drive_distance(-10);


}
/*---------------------------------------------------------------------------*/  
/*                            CLOSE SIDE SAFE                                */
/*---------------------------------------------------------------------------*/  
void CloseSideSafe() { 
  Intake.spin(reverse, 100, voltageUnits::volt);
  wait(0.3,seconds);
  Intake.stop();
}
/*---------------------------------------------------------------------------*/  
/*                            CLOSE SIDE RUSH                                */
/*---------------------------------------------------------------------------*/ 

void inertial_read() {
    Controller1.Screen.print(Inertial1.heading());
    Controller1.Screen.print(" ");
}

void CloseSideRushQual() { 
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
  chassis.drive_distance(-15, 170, 10, 12, 1.5, 300, 1200);

  // chassis.drive_distance(-10, 180);
  // Turn so that the back is parallel with the goal 
  // chassis.drive_distance( -20,  0,  12,  8);


  chassis.drive_distance(10, 160);
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

  chassis.drive_distance(25, 80);
  Intake.spin(reverse, 100, voltageUnits::volt);
  chassis.drive_distance(10);
  chassis.drive_distance(-3);
}



void CloseSideRushElim() { 
  //Drop Intake
  Intake.spin(reverse, 100, voltageUnits::volt);
  // Hit preload with flap 
  flaps.set(true);
  wait(0.3,seconds);
  flaps.set(false);
  Intake.stop();
  // Drive to get middle acorn
  Intake.spin(forward, 100, voltageUnits::volt);
  chassis.set_drive_exit_conditions(1.5, 300, 3000);
  chassis.drive_distance(50.5);
  chassis.set_drive_exit_conditions(1.5, 100, 3000);

  Intake.spin(forward, 7, voltageUnits::volt);

  // hit 1st acorn
  chassis.turn_to_angle(80, 12, 2, 100, 400);
  flaps.set(true);
  chassis.drive_distance(16);

  chassis.drive_distance(-16);
  // chassis.turn_to_angle(, 12, 2, 100, 700);

  flaps.set(false);
  // wait(0.3, seconds);
  
  chassis.turn_to_angle(0, 12, 2, 100, 400);

  chassis.drive_distance(-37, 2);
  chassis.drive_distance(-8, 90, 12, 8);
  chassis.drive_distance(-14);
  chassis.drive_distance(-12, 166, 10, 12, 1.5, 0, 1200);
  chassis.drive_distance(-6.5, 166, 12, 12, 1.5, 0, 500);
  // chassis.drive_distance(-10, 180);
  // Turn so that the back is parallel with the goal 
  // chassis.drive_distance( -20,  0,  12,  8);

  chassis.drive_distance(13, 160);
  // Turn to be parallel with match bar
  chassis.turn_to_angle(110, 12, 1.5, 100, 700);
  // Take acorn out of zone 
  BackRightFlap.set(true);

  chassis.drive_distance(16.5);
  // Whip it out of zone
  chassis.drive_distance(3, 60, 12, 12, 1, 300, 1500);
  chassis.drive_distance(5);
  chassis.turn_to_angle(-50, 12, 1.5, 300, 700);
  // chassis.drive_distance(0, -90);

  BackRightFlap.set(false);
  // Turn back to middle bar and outtake
  chassis.turn_to_angle(120, 12, 1.5, 300, 800);
  Intake.stop();
  inertial_read();

  wait(0.1, seconds);
  Intake.spin(reverse, 100, voltageUnits::volt);
  chassis.drive_distance(29, 80);
  chassis.drive_distance(-28);
  chassis.drive_distance(-10, 90);

}