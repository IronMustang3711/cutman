//
// Created by Jason Markham on 2/9/18.
//

#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>


struct RobotMap {



    Spark bucketMotor{0};
    Spark upperTiltMotor{1};
    Spark clampMotor{2};
    Spark clampTiltMotor{3};
    Spark winch{4};


    Encoder upperTiltEncoder{0,1,false,Encoder::k4X};
    Encoder bucketEncoder{2,3,false,Encoder::k4X};
    Encoder clampTiltEncoder{4,5,false,Encoder::k4X};
    Encoder clampEncoder{6,7,false,Encoder::k4X};

//    WPI_TalonSRX leftPrimary{1};
//    WPI_TalonSRX leftRear{2};
//    WPI_TalonSRX rightFront{3};
//    WPI_TalonSRX rightRear{4};
//
//    SpeedControllerGroup leftMotors{leftPrimary,leftRear};
//    SpeedControllerGroup rightMotors{rightFront,rightRear};
//
//    DifferentialDrive differentialDrive{leftMotors,rightMotors};

    PowerDistributionPanel powerDistributionPanel{};

    AHRS ahrs{SPI::Port::kMXP};

    RobotMap(){
        bucketMotor.SetName("bucket motor");
        upperTiltMotor.SetName("upper tilt motor");
        clampMotor.SetName("clamp motor");
        clampTiltMotor.SetName("clamp tilt motor");
        winch.SetName("winch motor");

        upperTiltEncoder.SetName("upper tilt encoder");
        upperTiltEncoder.SetDistancePerPulse(1.0);
        upperTiltEncoder.SetPIDSourceType(PIDSourceType::kDisplacement);

        bucketEncoder.SetName("bucket encoder");
        bucketEncoder.SetDistancePerPulse(1.0);
        bucketEncoder.SetPIDSourceType(PIDSourceType::kDisplacement);


        clampTiltEncoder.SetName("clamp tilt encoder");
        clampTiltEncoder.SetDistancePerPulse(1.0);
        clampTiltEncoder.SetPIDSourceType(PIDSourceType::kDisplacement);

        clampEncoder.SetName("clamp encoder");
        clampEncoder.SetDistancePerPulse(1.0);
        clampEncoder.SetPIDSourceType(PIDSourceType::kDisplacement);


//        leftPrimary.SetName("left front");
//        leftRear.SetName("left rear");
//        leftMotors.SetName("left drive motors");
//
//        rightFront.SetName("right front");
//        rightRear.SetName("right rear");
//        rightMotors.SetName("right drive motors");
//
//        differentialDrive.SetName("differential drive");
//        differentialDrive.SetSafetyEnabled(true);
//        differentialDrive.SetExpiration(0.5);
//        differentialDrive.SetMaxOutput(1.0);

        powerDistributionPanel.SetName("power distribution panel");

        ahrs.SetName("navx");



    }

};
