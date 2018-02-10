//
// Created by Jason Markham on 2/9/18.
//

#include "UpperTilt.h"

UpperTilt::UpperTilt(frc::PIDOutput &motor, frc::PIDSource &encoder)
        : UpperTilt{0.03, 0.0, 0.0,0.0 ,motor,encoder} { }

UpperTilt::UpperTilt(double p, double i, double d, double f, frc::PIDOutput &_motor, frc::PIDSource &_encoder)
        : SimplePIDSubsystem{"Upper Tilt",p,i,d,f,0.05,_motor,_encoder}
{
    SetAbsoluteTolerance(5.0);
    GetPIDController()->SetContinuous(false);
    GetPIDController()->SetName("Upper Tilt PID controller");
}


