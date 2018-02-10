//
// Created by Jason Markham on 2/9/18.
//

#include "Winch.h"

Winch::Winch(SpeedController &_motor)
        : frc::Subsystem{"Winch"}, motor{_motor} {}

void Winch::driveWinch(double output) {
    motor.Set(output);
}
