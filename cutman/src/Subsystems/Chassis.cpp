//
// Created by Jason Markham on 2/9/18.
//

#include "Chassis.h"

Chassis::Chassis(DifferentialDrive &_drive) : frc::Subsystem{"chassis"},drive{_drive}{
    AddChild(_drive);

}
