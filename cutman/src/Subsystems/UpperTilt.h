//
// Created by Jason Markham on 2/9/18.
//

#include "SimplePIDSubsystem.h"

class UpperTilt : public SimplePIDSubsystem {

public:
    UpperTilt(frc::PIDOutput& motor, frc::PIDSource& encoder);

protected:
    UpperTilt(double p, double i, double d, double f,
              frc::PIDOutput &_motor, frc::PIDSource &_encoder);
};
