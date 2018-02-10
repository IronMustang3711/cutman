//
// Created by Jason Markham on 2/9/18.
//

#include "Clamp.h"

Clamp::Clamp(frc::PIDOutput &motor, frc::PIDSource &encoder)
    : Clamp{0.02, 0.0, 0.0,0.0 ,motor,encoder} { }

Clamp::Clamp(double p, double i, double d, double f, frc::PIDOutput &_motor, frc::PIDSource &_encoder)
    : SimplePIDSubsystem{"Clamp",p,i,d,f,0.05,_motor,_encoder}
{
    SetAbsoluteTolerance(5.0);
    GetPIDController()->SetContinuous(false);
    GetPIDController()->SetName("clamp PID controller");
}
