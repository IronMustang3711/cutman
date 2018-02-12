/*
 * ClampCommands.h
 *
 *  Created on: Feb 11, 2018
 *      Author: jason
 */
#pragma once

#include "SimpleSetpointCommand.h"


class OpenClamp : public SimpleSetpointCommand {
public:
    explicit OpenClamp(frc::PIDController *pid);
};

class CloseClamp : public SimpleSetpointCommand {
public:
    explicit CloseClamp(frc::PIDController *controller);
};
