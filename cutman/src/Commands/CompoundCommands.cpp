//
// Created by Jason Markham on 2/12/18.
//

#include "CompoundCommands.h"
#include "BucketTiltPosition.h"
#include "UpperTiltPosition.h"
#include "ClampCommands.h"
#include "DelayCommand.h"

DumpCube::DumpCube(PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem) : CommandGroup("Dump Cube"){
    AddSequential(new BucketTiltPosition(200,&bucketSubsystem,&upperTiltSubsystem));  // 200 is selecto dump
    AddSequential(new DelayCommand(0.5));
    AddSequential(new BucketTiltPosition(-20,&bucketSubsystem,&upperTiltSubsystem));  // Back to home

}

GoToScale::GoToScale(PIDController& clampController,PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem): CommandGroup("Go To Scale") {
    // stow clamp
    AddSequential(new StowClamp(clampController));  // Hide clamp

    AddParallel(new BucketTiltPosition(100,&bucketSubsystem,&upperTiltSubsystem));  // Put bucket in auto level
    AddParallel(new UpperTiltPosition(430,upperTiltSubsystem));  // move arm to scale

}

GoToSwitch::GoToSwitch(PIDController& clampController,PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem)
        : CommandGroup("Go To Switch"){
    // stow clamp
    AddSequential(new StowClamp(clampController));  // Hide clamp

    AddParallel(new BucketTiltPosition(100,&bucketSubsystem,&upperTiltSubsystem));  // Put bucket in auto level
    AddParallel(new UpperTiltPosition(150,upperTiltSubsystem));  // move arm to switch

}

StowBucket::StowBucket(PIDController& clampController, PIDSubsystem& bucketSubsystem, PIDSubsystem& upperTiltSubsystem) : CommandGroup("Stow Bucket"){

    AddSequential(new StowClamp(clampController));  // Hide clamp.  Should already be hid
    AddSequential(new BucketTiltPosition(-15,&bucketSubsystem,&upperTiltSubsystem));  // Back to home
    AddSequential(new UpperTiltPosition(0,upperTiltSubsystem));  // move arm to home

}

StowClamp::StowClamp(PIDController& clampController): CommandGroup("Stow Clamp") {
    AddSequential(new OpenClamp(&clampController));  // Open Clamp
    AddSequential(new CloseClamp(&clampController));  // stow below
}
