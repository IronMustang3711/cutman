//
// Created by Jason Markham on 2/9/18.
//

#include "Chassis.h"

constexpr inline
double clamp(double value,double min,double max){
   return value < min ? min : value > max ? max : value;
}
constexpr inline
double clamp(double value){ return clamp(value,-1.0,1.0);}

Chassis &Chassis::getInstance() {
    static Chassis instance;
    return instance;
}

Chassis::Chassis() : Subsystem{"Chassis"} {

    leftPrimary.SetName("left primary");
    leftFollower.SetName("left follower");
    leftFollower.Follow(leftPrimary);

    //leftMotors.SetName("left drive motors");

    rightPrimary.SetName("right primary");
    rightFollower.SetName("right follower");
    rightFollower.Follow(rightPrimary);
    //rightMotors.SetName("right drive motors");

//    differentialDrive.SetName("differential drive");
//    differentialDrive.SetSafetyEnabled(true);
//    differentialDrive.SetExpiration(0.5);
//    differentialDrive.SetMaxOutput(1.0);

    leftMotors = &leftPrimary;
    rightMotors = &rightPrimary;

}

void Chassis::arcadeDrive(double speed, double rotation) {

    speed = clamp(speed);

    rotation = clamp(rotation);



    double leftMotorOutput;
    double rightMotorOutput;

    double maxInput =
            std::copysign(std::max(std::abs(speed), std::abs(rotation)), speed);

    if (speed >= 0.0) {
        // First quadrant, else second quadrant
        if (rotation >= 0.0) {
            leftMotorOutput = maxInput;
            rightMotorOutput = speed - rotation;
        } else {
            leftMotorOutput = speed + rotation;
            rightMotorOutput = maxInput;
        }
    } else {
        // Third quadrant, else fourth quadrant
        if (rotation >= 0.0) {
            leftMotorOutput = speed + rotation;
            rightMotorOutput = maxInput;
        } else {
            leftMotorOutput = maxInput;
            rightMotorOutput = speed - rotation;
        }
    }

    leftMotorOutput = clamp(leftMotorOutput) * maxOutput;
    rightMotorOutput = -clamp(rightMotorOutput) * maxOutput;



    leftMotors->Set(leftMotorOutput);
    rightMotors->Set(rightMotorOutput);



}

void Chassis::curvatureDrive(double speed, double rotation, bool isQuickTurn) {

    speed = clamp(speed);

    rotation = clamp(rotation);

    double angularPower;
    bool overPower;

    if (isQuickTurn) {
        if (std::abs(speed) < quickStopThreshold) {
            quickStopAccumulator = (1 - quickStopAlpha) * quickStopAccumulator +
                                     quickStopAlpha * clamp(rotation) * 2;
        }
        overPower = true;
        angularPower = rotation;
    } else {
        overPower = false;
        angularPower = std::abs(speed) * rotation - quickStopAccumulator;

        if (quickStopAccumulator > 1) {
            quickStopAccumulator -= 1;
        } else if (quickStopAccumulator < -1) {
            quickStopAccumulator += 1;
        } else {
            quickStopAccumulator = 0.0;
        }
    }

    double leftMotorOutput = speed + angularPower;
    double rightMotorOutput = speed - angularPower;

    // If rotation is overpowered, reduce both outputs to within acceptable range
    if (overPower) {
        if (leftMotorOutput > 1.0) {
            rightMotorOutput -= leftMotorOutput - 1.0;
            leftMotorOutput = 1.0;
        } else if (rightMotorOutput > 1.0) {
            leftMotorOutput -= rightMotorOutput - 1.0;
            rightMotorOutput = 1.0;
        } else if (leftMotorOutput < -1.0) {
            rightMotorOutput -= leftMotorOutput + 1.0;
            leftMotorOutput = -1.0;
        } else if (rightMotorOutput < -1.0) {
            leftMotorOutput -= rightMotorOutput + 1.0;
            rightMotorOutput = -1.0;
        }
    }

    leftMotorOutput  *= maxOutput;
    rightMotorOutput *= -maxOutput;

    leftMotors->Set(leftMotorOutput);
    rightMotors->Set(rightMotorOutput);


}
