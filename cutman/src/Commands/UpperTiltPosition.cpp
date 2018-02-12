//
// Created by Jason Markham on 2/12/18.
//

#include "UpperTiltPosition.h"

UpperTiltPosition::UpperTiltPosition(double _setpoint, PIDSubsystem &_upperTilt)
        : Command("Upper Tilt Position"),setpoint{_setpoint},upperTilt{_upperTilt}
{
    Requires(&upperTilt);
    SetTimeout(5.0);

//    holdPower = 0.2;  // this is 20% of max power
//    maxPower = 1.0;
//    // with 1 14000rmp motor and 245:1 gearbox and a 1024 cpr encoder
//    // maxVelocity is about 14000rpm/60/245 = 1 rps * 1024 counts/sec.
//    maxVelocity = 1000;  // encoder counts per second (about 1/3 rev/sec
//    velocityP = 0.001;
//    velocityFF = 1 / maxVelocity;
//    acceleration = 600;  // accel to 300 counts/sec in one second
//    deceleration = 600;
//    PIDband = 15;  // switch to PID when within this band.
}

void UpperTiltPosition::Initialize() {
  //  upperTilt.Enable();
    upperTilt.SetSetpoint(setpoint);
    upperTilt.SetOutputRange(-maxPower,maxPower);

    prevPosition = upperTilt.GetPosition();

    if(fabs(setpoint-prevPosition) < PIDband){
        velocityControl = false;
        upperTilt.Enable();
    } else{
        velocityControl = true;
        upperTilt.Disable();
    }

    // if going down, select slower velocity.
    if (setpoint > prevPosition)
        targetVelocity = 400; // going up
    else
        targetVelocity = 200; // going down;


}

void UpperTiltPosition::Execute() {
    double currentTime = Timer::GetFPGATimestamp();
    double elapsedTime = currentTime - startTime;

    // now determine if we are in velocity or position control.
    double currentPosition = upperTilt.GetPosition();
    double distanceToTarget = setpoint - currentPosition;
    SmartDashboard::PutNumber("Upper", currentPosition);

    if (velocityControl &&                        // are we controlling velocity?
        fabs(distanceToTarget) < PIDband) {  // are we near target?
        velocityControl = false;
        upperTilt.Enable();  // go to PID distance control
    }

    // if in velocityControl do things, otherwise let PID do things.
    if (velocityControl) {
        // see if we should be accelerating
        double desiredVelocity = acceleration * (elapsedTime);
        if (desiredVelocity > targetVelocity)
            desiredVelocity = targetVelocity;   //should be done accelerating

        // now estimate distance required to decelerate to target
        double distanceToStop = desiredVelocity * desiredVelocity / (2 * deceleration);
        double remainingDistance = fabs(distanceToTarget);
        if (distanceToStop >= remainingDistance)
            desiredVelocity = sqrt(2 * remainingDistance * deceleration);

        // make a minimum velocity to get things moving and keep moving to target
        if (desiredVelocity < (targetVelocity / 5)) // make them minimum velocity 1/5 target
            desiredVelocity = targetVelocity / 5;
        // get the direction set.
        if (distanceToTarget < 0)
            desiredVelocity *= -1; // go in negative direction.

        double currentVelocity = (currentPosition - prevPosition) / (currentTime - prevTime); //(Robot::upperTilt->GetRate();
        double velocityError = desiredVelocity - currentVelocity;

        double drivePower = velocityFF * desiredVelocity + // this is the feedforward component
                            velocityP * velocityError;  // the is the proportional component

        if (drivePower > maxPower)
            drivePower = maxPower;
        else if (drivePower < -maxPower)
            drivePower = -maxPower;

        //TODO: IMPORTANT!
       // Robot::upperTilt->upperMotor->Set(drivePower);

        /*	printf("et,sp,cp,dt,vc,cv,tv,d2s,dv,dp %5.2f %3.0f %3.0f %3.0f %d %3.0f %3.0f %3.0f %3.0f %4.2f \n",
            elapsedTime,
            m_setpoint,
            currentPosition,
            distanceToTarget,
            velocityControl,
            currentVelocity,
            targetVelocity,
            distanceToStop,
            desiredVelocity,
            drivePower);
    */

    }
    prevPosition = currentPosition;
    prevTime = currentTime;
}

void UpperTiltPosition::End() {
    if(IsTimedOut()) velocityControl = false;
}

bool UpperTiltPosition::IsFinished() {
    return IsTimedOut();
}
