#pragma once

#include <Commands/Subsystem.h>
#include <SpeedController.h>


class Winch : public frc::Subsystem {

public:
    Winch(SpeedController& motor);

    void driveWinch(double output);

private:
    SpeedController& motor;

};


