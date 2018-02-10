#pragma once

#include "SimplePIDSubsystem.h"

class Clamp : public SimplePIDSubsystem {

public:
    Clamp(frc::PIDOutput& motor, frc::PIDSource& encoder);

protected:
    Clamp(double p, double i, double d, double f,
           frc::PIDOutput &_motor, frc::PIDSource &_encoder);
};



