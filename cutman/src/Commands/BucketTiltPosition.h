//
// Created by Jason Markham on 2/12/18.
//

#pragma once
#include <WPILib.h>
class BucketTiltPosition : public frc::Command {
public:
    BucketTiltPosition(double setpoint,frc::PIDSubsystem* bucket,frc::PIDSubsystem* upperTilt);

protected:
    void Initialize() override ;
    void Execute() override ;
    bool IsFinished() override ;


private:
    double setpoint;
    frc::PIDSubsystem* bucket;
    frc::PIDSubsystem* upperTilt;
};


