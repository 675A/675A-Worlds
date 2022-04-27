#include "main.h"

// constructors are (port, gearset, reverse, encoder_units)
// blue = 600 rpm gearset_6
// green = 200 rpm gearset_18
// red = 100 rpm gearset_36

pros::Motor lift(9, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
pros::Motor conveyor(8, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut backClamp('B', false);
pros::ADIDigitalOut leftClamp('C', true);
pros::ADIDigitalOut rightClamp('D', true);
pros::ADIDigitalOut canstealer('E', false);
