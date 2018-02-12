/*
 * ClampCommands.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: jason
 */

#include "ClampCommands.h"

OpenClamp::OpenClamp(frc::PIDController* pid) :
		SimpleSetpointCommand("Open Clamp", 2.0, pid, 220) {
}

CloseClamp::CloseClamp(frc::PIDController* pid) :
		SimpleSetpointCommand("Close Clamp", 2.0, pid, 0) {
}
