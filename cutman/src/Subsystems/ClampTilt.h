//
// Created by Jason Markham on 2/9/18.
//
#pragma once

#include "SimplePIDSubsystem.h"

class ClampTilt : public SimplePIDSubsystem {

public:
    ClampTilt(frc::PIDOutput& motor, frc::PIDSource& encoder);

protected:
    ClampTilt(double p, double i, double d, double f,
          frc::PIDOutput &_motor, frc::PIDSource &_encoder);
};
