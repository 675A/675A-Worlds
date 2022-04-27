#include "main.h"

void frontClampOpen()
{
  leftClamp.set_value(false);
  rightClamp.set_value(false);
  frontClampIsDown = false;
}
void frontClampClose()
{
  leftClamp.set_value(true);
  rightClamp.set_value(true);
  frontClampIsDown = true;
}

void backClampDown()
{
  backClamp.set_value(true);
  backClampIsDown = true;
}

void backClampUp()
{
  backClamp.set_value(false);
  backClampIsDown = false;
}

void startLiftTo(int pos, int speed)
{
  lift.move_absolute(pos, speed);
}

void liftTo(int pos, int speed)
{
  lift.move_absolute(pos, speed);

  while(fabs(lift.get_position() - lift.get_target_position()) > 2){
    wait(2);
  }
}

void startIntake(int speed)
{
  conveyor.move_velocity(speed);
}

void stopIntake()
{
  conveyor.move_velocity(0);
}

void startIntakeFor(int deg, int speed)
{
  conveyor.move_relative(deg, speed);
}

void intakeFor(int deg, int speed)
{
  conveyor.tare_position();
  conveyor.move_absolute(deg, speed);

  while(fabs(conveyor.get_position() - conveyor.get_target_position()) > 2){
    wait(2);
  }
}

void wait(int time){
  pros::delay(time);
}
