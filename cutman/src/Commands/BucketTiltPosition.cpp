//
// Created by Jason Markham on 2/12/18.
//

#include "BucketTiltPosition.h"



void BucketTiltPosition::Initialize() {
    bucket->Enable();

    if(setpoint != 100)
        bucket->SetSetpoint(setpoint);

    bucket->SetOutputRange(-0.8,0.8);
}

void BucketTiltPosition::Execute() {
   //TODO:!!!
}

bool BucketTiltPosition::IsFinished() {
   if(setpoint == 100) return false;
    return bucket->OnTarget();
}

BucketTiltPosition::BucketTiltPosition(double _setpoint, frc::PIDSubsystem *_bucket, frc::PIDSubsystem *_upperTilt)
: Command("Bucket Tilt Position") ,setpoint{_setpoint},bucket{bucket},upperTilt{_upperTilt} {

}
