#include "api.h"

void frontClampOpen();
void frontClampClose();

void backClampDown();
void backClampUp();

////
// moves lift to the specified position at the specified speed
// NON-BLOCKING
////
void startLiftTo(int pos, int speed);

////
// moves lift to the specified position at the specified speed
// BLOCKING
////
void liftTo(int pos, int speed);

////
// begins running the intake at the specified speed
// NON-BLOCKING
////
void startIntake(int speed);

////
// stops the intake
// NON-BLOCKING
////
void stopIntake();

////
// moves conveyor for the specified distance at the specified speed
// NON-BLOCKING
////
void startIntakeFor(int deg, int speed);

////
// moves conveyor for the specified distance at the specified speed
// BLOCKING
////
void intakeFor(int deg, int speed);

////
// wait block
////
void wait(int time);
