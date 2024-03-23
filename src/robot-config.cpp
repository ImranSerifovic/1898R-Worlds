#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Left1 = motor(PORT1, ratio6_1, false);
motor Left2 = motor(PORT2, ratio6_1, false);
motor Left3 = motor(PORT3, ratio6_1, false);
motor Left4 = motor(PORT4, ratio18_1, false);
motor Right1 = motor(PORT5, ratio6_1, false);
motor Right2 = motor(PORT6, ratio6_1, false);
motor Right3 = motor(PORT7, ratio18_1, false);
motor Right4 = motor(PORT8, ratio18_1, false);
inertial Inertial1 = inertial(PORT9);
inertial Inertial2 = inertial(PORT10);
inertial Inertial3 = inertial(PORT11);
motor Intake = motor(PORT12, ratio6_1, false);
digital_out LeftFlap = digital_out(Brain.ThreeWirePort.A);
digital_out RightFlap = digital_out(Brain.ThreeWirePort.B);
digital_out BackLeftFlap = digital_out(Brain.ThreeWirePort.C);
digital_out BackRightFlap = digital_out(Brain.ThreeWirePort.D);
digital_out PTO = digital_out(Brain.ThreeWirePort.E);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}