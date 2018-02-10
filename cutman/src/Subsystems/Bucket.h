//
// Created by Jason Markham on 2/9/18.
//

#pragma once

#include <Commands/PIDSubsystem.h>
#include <SpeedController.h>
#include <Encoder.h>
#include "SimplePIDSubsystem.h"

class Bucket : public SimplePIDSubsystem{
public:
    Bucket(frc::PIDOutput& motor, frc::PIDSource& encoder);

protected:
    Bucket(double p, double i, double d, double f,
           frc::PIDOutput &_motor, frc::PIDSource &_encoder);


};



