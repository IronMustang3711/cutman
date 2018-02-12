/*
 * SimpleSetpointCommand.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: jason
 */

#include "SimpleSetpointCommand.h"

SimpleSetpointCommand::SimpleSetpointCommand(const llvm::Twine& name,
		double timeout, frc::PIDController* pid, double _setpoint) :
		frc::Command(name, timeout), controller { pid }, setpoint { _setpoint } {
}

void SimpleSetpointCommand::Initialize() {
	controller->Enable();
}

void SimpleSetpointCommand::Execute() {
	controller->SetSetpoint(setpoint);
}

bool SimpleSetpointCommand::IsFinished() {
	return controller->OnTarget();
}

void SimpleSetpointCommand::End() {
	controller->Disable();
}
