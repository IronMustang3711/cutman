//
// Created by Jason Markham on 2/9/18.
//
#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

class Chassis : public Subsystem {
public:
    Chassis(DifferentialDrive& drive);

private:
    frc::DifferentialDrive& drive;

};


