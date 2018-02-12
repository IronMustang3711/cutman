//
// Created by Jason Markham on 2/9/18.
//
#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

class Chassis : public Subsystem {
public:
    static Chassis& getInstance();

    void arcadeDrive(double speed,double rotation);
    void curvatureDrive(double fwdSpeed,double rotation,bool isQuickTurn);

    static constexpr double kDefaultQuickStopThreshold = 0.2;
    static constexpr double kDefaultQuickStopAlpha = 0.1;

private:
    Chassis();

    WPI_TalonSRX leftPrimary{1};
    WPI_TalonSRX leftFollower{2};
    WPI_TalonSRX rightPrimary{3};
    WPI_TalonSRX rightFollower{4};

   // SpeedControllerGroup leftMotors{leftPrimary,leftFollower};
    //SpeedControllerGroup rightMotors{rightPrimary,rightFollower};

    //DifferentialDrive differentialDrive{leftMotors,rightMotors};

    SpeedController* leftMotors;
    SpeedController* rightMotors;


    double maxOutput = 1.0;
    double quickStopThreshold = kDefaultQuickStopThreshold;
    double quickStopAlpha = kDefaultQuickStopAlpha;
    double quickStopAccumulator = 0.0;

};


