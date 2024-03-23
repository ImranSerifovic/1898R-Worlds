using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Left1;
extern motor Left2;
extern motor Left3;
extern motor Left4;
extern motor Right1;
extern motor Right2;
extern motor Right3;
extern motor Right4;
extern inertial Inertial1;
extern inertial Inertial2;
extern inertial Inertial3;
extern motor Intake;
extern digital_out LeftFlap;
extern digital_out RightFlap;
extern digital_out BackLeftFlap;
extern digital_out BackRightFlap;
extern digital_out PTO;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );