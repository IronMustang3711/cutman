/*
 * SimpleSetpointCommand.h
 *
 *  Created on: Feb 11, 2018
 *      Author: jason
 */

#pragma once
#include <WPILib.h>

class SimpleSetpointCommand: public frc::Command {
public:
	SimpleSetpointCommand(const llvm::Twine& name, double timeout,
			frc::PIDController* pid, double setpoint);

protected:
	//	  void _Initialize() override;
	//	  void _Interrupted() override;
	//	  void _End() override;
	//	  void _Execute() override;

	void Initialize() override;

	void Execute() override;

	bool IsFinished() override;

	void End() override;

protected:
	frc::PIDController* controller;
	double setpoint;
};

