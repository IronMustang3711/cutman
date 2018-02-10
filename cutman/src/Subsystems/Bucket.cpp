//
// Created by Jason Markham on 2/9/18.
//

#include "Bucket.h"
#include "SimplePIDSubsystem.h"




Bucket::Bucket(frc::PIDOutput& motor, frc::PIDSource &encoder)
        : Bucket{0.025,0.0,0.0,0.0,motor,encoder} {}



Bucket::Bucket(double p, double i, double d, double f, frc::PIDOutput &_motor, frc::PIDSource &_encoder)
        : SimplePIDSubsystem{"Bucket",p,i,d,f,0.05,_motor,_encoder}
{
    SetAbsoluteTolerance(5.0);
    GetPIDController()->SetContinuous(false);
}
