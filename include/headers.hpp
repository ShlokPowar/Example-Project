//Intake
static pros::Motor intake(3, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

//indexers
// static pros::ADIDigitalOut index1('C', false);
static pros::ADIDigitalOut indexer('H', false);

//flywheel
static pros::Motor flywheel(1, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

// //expansion
// static pros::ADIDigitalOut piston1('A', false);
// static pros::ADIDigitalOut piston2('B', false);