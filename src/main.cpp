#include "vex.h"
using namespace vex;
competition Competition;

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left1                motor         1               
// Left2                motor         2               
// Left3                motor         3               
// Left4                motor         4               
// Right1               motor         5               
// Right2               motor         6               
// Right3               motor         7               
// Right4               motor         8               
// Inertial1            inertial      9               
// Inertial2            inertial      10              
// Inertial3            inertial      11              
// Intake               motor         12              
// LeftFlap             digital_out   A               
// RightFlap            digital_out   B               
// BackLeftFlap         digital_out   C               
// BackRightFlap        digital_out   D               
// PTO                  digital_out   E               
// ---- END VEXCODE CONFIGURED DEVICES ----

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                CONFIG SECTION                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
Drive chassis(
ZERO_TRACKER_NO_ODOM,
//Left Motors:
motor_group(Left1, Left2, Left3, Left4),
//Right Motors:
motor_group(Right1, Right2, Right3, Right4),
//Devan do ur thing with the inertial sensor
PORT1,
//wheel diameter
2.75,
//Gear ratio
1,
//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
360,
//remainder is for odom
PORT1,     -PORT2,
PORT3,     -PORT4,
3,
2.75,
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,
1,
-2.75,
5.5
);

bool auto_started = false;
/*---------------------------------------------------------------------------*/
//Pre auton
void pre_auton(void) {
  // Initialize robot config
  vexcodeInit();
  default_constants();
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  AUTONS                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
  auto_started = true;
  //put auton here

}
/*---------------------------------------------------------------------------*/




/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                DRIVE SECTION                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  while (1) {
    
    //type of control(currently tank)
    chassis.control_tank();
    wait(20, msec); 
  }
}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
//sets up competition functions and callbacks
int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  //run pre-auton
  pre_auton();

  //failsaife
  while (true) {
    wait(100, msec);
  }
}
/*---------------------------------------------------------------------------*/