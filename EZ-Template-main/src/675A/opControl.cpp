#include "main.h"


//MAIN USER CONTROL LOOP--------------------------------------------------------
void opControl()
{
  useDriveLock();  //Y
  useBackClamp();  //A
  useFrontClamp();  //R1
  useLift();  //L1 & L2
  useConveyor();  //R2 & X
  useCanstealer();  //B

  // if lift value is under 20 make conveyor stop no matter what
  if (lift.get_position() <= 20)
  {
    conveyor.move_velocity(0);
  }
}


//MANUAL USER CONTROL-----------------------------------------------------------
void useDriveLock()
{
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
  {
    pros::Task driveLockTask(driveLockSwitch);
  }

  if (driveLock)
  {
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  }
  else if (driveLock == false)
  {
    chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  }
}

void useBackClamp()
{
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
  {
    if(backClampIsDown == true)
    {
      backClamp.set_value(false);
      backClampIsDown = false;
    }
    else if(backClampIsDown == false)
    {
      backClamp.set_value(true);
      backClampIsDown = true;
    }
  }
}

void useFrontClamp()
{
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
  {
    if(frontClampIsDown == true)
    {
      leftClamp.set_value(false);
      rightClamp.set_value(false);
      frontClampIsDown = false;
    }
    else if(frontClampIsDown == false)
    {
      leftClamp.set_value(true);
      rightClamp.set_value(true);
      frontClampIsDown = true;
    }
  }
}

void useCanstealer()
{
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
  {
    if(canstealerIsDown == true)
    {
      canstealer.set_value(false);
      canstealerIsDown = false;
    }
    else if(canstealerIsDown == false)
    {
      canstealer.set_value(true);
      canstealerIsDown = true;
    }
  }
}

void useLift()
{
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
  {
    lift.move_velocity(liftUpSpeed);
  }
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
  {
    lift.move_velocity(-liftUpSpeed);
  }
  else
  {
    lift.move_velocity(0);
  }
}

void useConveyor()
{
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2))
  {
    if (conveyorIsOn == false)
    {
    conveyor.move_velocity(conveyorSpeed);
    conveyorIsOn = true;
    }
    if (conveyorIsOn == true)
    {
      conveyor.move_velocity(-conveyorSpeed);
      conveyorIsOn = false;
    }
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
  {
    conveyor.move_velocity(0);
  }
}


//USER CONTROL TASKS------------------------------------------------------------
int driveLockSwitch()
{
  if (driveLock)  //disable
  {
    driveLock = false;
    master.rumble("-");
  }
  else if (driveLock == false)  //enable
  {
    driveLock = true;
    master.rumble("--");
  }
  return 1;
}

void startDriveLockSwitch()
{
  pros::Task b(driveLockSwitch);
}
