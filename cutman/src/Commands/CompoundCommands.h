//
// Created by Jason Markham on 2/12/18.
//

#pragma once



#include <WPILib.h>

struct DumpCube : public CommandGroup {
    DumpCube(PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem);

};
struct GoToScale : public CommandGroup {
    GoToScale(PIDController& clampController,PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem);
};

struct GoToSwitch : public CommandGroup {
    GoToSwitch(PIDController& clampController,PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem);
};

struct StowBucket : public CommandGroup {
    StowBucket(PIDController& clampController, PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem);
};

struct StowClamp : public CommandGroup {
    explicit StowClamp(PIDController& clampController);
};


//namespace CompoundCommands {
//
//    frc::Command& dumpCubeCommand();
//    frc::Command& GoToScaleCommand();
//    frc::Command& GoToSwitchCommand();
//    frc::Command& stowBucketCommand();
//    frc::Command& stowClampCommand();
//
//};


