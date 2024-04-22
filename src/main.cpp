#include "vex.h"
using namespace vex;
competition Competition;

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left1                motor         8               
// Left2                motor         9               
// Left3                motor         7               
// Left4                motor         6               
// Right1               motor         4               
// Right2               motor         3               
// Right3               motor         5               
// Right4               motor         2               
// Inertial1            inertial      21              
// Intake               motor         1               
// BackLeftFlap         digital_out   C               
// BackRightFlap        digital_out   B               
// PTO                  digital_out   F               
// flaps                digital_out   A               
// hangRelease          digital_out   G               
// ---- END VEXCODE CONFIGURED DEVICES ----

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                CONFIG SECTION                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
Drive chassis(

//Specify your drive setup below. There are eight options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
 ZERO_TRACKER_NO_ODOM,
//TANK_TWO_ROTATION, // skillschange
//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(Left1, Left2, Left3, Left4),

//Right Motors:
motor_group(Right1, Right2, Right3, Right4),

//Port number of inertial sensors.
PORT21,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
1,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
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
  // pidTest();
   //CloseSideRushQual();
  //CloseSideRushElim();
  // FarSideSafe();
  // CloseSideSafe();
  fiveballfar();
}
/*---------------------------------------------------------------------------*/




/*---------------------------------------------------------------------------*/
/*                              OTHER FUNCTIONS                              */
/*---------------------------------------------------------------------------*/
// Flaps
void Flaps() { 
  flaps.set(!flaps.value());
}

// Left Back Flap
void LeftBackFlap() { 
  BackLeftFlap.set(!BackLeftFlap.value());
}

// Right Back Flap
void RightBackFlap() { 
  BackRightFlap.set(!BackRightFlap.value());
}

void BothFlaps() { 
 BackRightFlap.set(!BackRightFlap.value());
 BackLeftFlap.set(!BackLeftFlap.value());
}

// PTO
void setPTO() { 
  PTO.set(!PTO.value());
}

// Hang Release
void HangRelease() {
  hangRelease.set(true);
  wait(0.2, seconds);
  hangRelease.set(false);
}

// Pneumatic Shut-Off
void falsePistons() { 
  flaps.set(false);
  BackLeftFlap.set(false);
  BackRightFlap.set(false);
  PTO.set(false);
  hangRelease.set(false);
}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                DRIVE SECTION                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // set all pistons to false as a failsafe
  falsePistons();

  while (1) {

    // Intake
    if (Controller1.ButtonR1.pressing()) {
      Intake.spin(forward, 100,  voltageUnits::volt);
    } 
    else if (Controller1.ButtonR2.pressing()) {
       Intake.spin(reverse, 100,  voltageUnits::volt);
    } 
    else {
      Intake.stop();
    }

    // Callbacks for pistons
    Controller1.ButtonL2.pressed(Flaps);
    Controller1.ButtonA.pressed(RightBackFlap);
    Controller1.ButtonLeft.pressed(LeftBackFlap);
    Controller1.ButtonB.pressed(setPTO);
    Controller1.ButtonDown.pressed(HangRelease);
    Controller1.ButtonL1.pressed(BothFlaps);

    // type of control(currently tank)
    chassis.control_tank();
    // chassis.control_arcade(); // REVEAL
    wait(20, msec); 
  }
}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
//sets up competition functions and callbacks
int main() {
  // Set all pistons to false at start 
  falsePistons();

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