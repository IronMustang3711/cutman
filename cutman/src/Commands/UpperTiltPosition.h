//
// Created by Jason Markham on 2/12/18.
//

#pragma once

#include <WPILib.h>


class UpperTiltPosition : public Command {

public:
    UpperTiltPosition(double setpoint, PIDSubsystem& upperTiltSubsystem);

protected:
    void Initialize() override ;
    void Execute() override ;
    void End() override ;
    bool IsFinished() override ;

private:
    double setpoint;
    PIDSubsystem& upperTilt;

    double startTime=0;
    double prevTime=0;
    double prevPosition=0;
    double holdPower = 0.2;  // this is 20% of max power
    double maxPower = 1.0;
    double maxVelocity = 1000;  // encoder counts per second (about 1/3 rev/sec
    double targetVelocity = 0;  // usually 1/2 maxVelocity;
    double velocityP = 0.001;  // proportional control
    double velocityFF = 1 / maxVelocity;  // feedforward control
    double acceleration = 600;  // accel to 300 counts/sec in one second
    double deceleration = 600;
    double PIDband = 15;  // switch to PID when within this band.
    bool velocityControl=false;  // velocity or PID distance control
};


