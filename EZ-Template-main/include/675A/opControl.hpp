#include "api.h"

extern pros::Task driveLockTask();

void opControl();

// user control macros
void startDriveLockSwitch();
int driveLockSwitch();

// manual user control
void useDriveLock();
void useBackClamp();
void useFrontClamp();
void useLift();
void useConveyor();
void useCanstealer();
