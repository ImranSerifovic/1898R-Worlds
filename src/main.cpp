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
  pidTest();
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

// PTO
void setPTO() { 
  PTO.set(!PTO.value());
}

// Hang Release
void HangRelease() {
  hangRelease.set(!hangRelease.value());
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

    // type of control(currently tank)
    chassis.control_tank();
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