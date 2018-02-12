//
// Created by Jason Markham on 2/9/18.
//
#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>


template<typename Derived>
class DifferentialDriveLite {
public:
    void arcadeDrive(double speed, double rotation);

    void curvatureDrive(double fwdSpeed, double rotation, bool isQuickTurn);

protected:
    //void setLeftOutput(double output);
    //void setRightOutput(double output);

    static constexpr double kDefaultQuickStopThreshold = 0.2;
    static constexpr double kDefaultQuickStopAlpha = 0.1;

    double maxOutput = 1.0;
    double quickStopThreshold = kDefaultQuickStopThreshold;
    double quickStopAlpha = kDefaultQuickStopAlpha;
    double quickStopAccumulator = 0.0;

};


class TalonSRXDifferentialDrive : public DifferentialDriveLite<TalonSRXDifferentialDrive> {

public:
    TalonSRXDifferentialDrive(TalonSRX &l, TalonSRX &r);

protected:
    void setLeftOutput(double output);

    void setRightOutput(double output);

private:
    TalonSRX &left;
    TalonSRX &right;

};

class WPIDifferentialDrive : public DifferentialDriveLite<WPIDifferentialDrive> {
public:
    WPIDifferentialDrive(SpeedController &l, SpeedController &r);

protected:
    void setLeftOutput(double output);

    void setRightOutput(double output);

private:
    frc::SpeedController &left;
    frc::SpeedController &right;
};


class Chassis : public Subsystem {
public:
    static Chassis &getInstance();

    void arcadeDrive(double speed, double rotation);

    void curvatureDrive(double fwdSpeed, double rotation, bool isQuickTurn);


private:
    Chassis();

    WPI_TalonSRX leftPrimary{1};
    WPI_TalonSRX leftFollower{2};
    WPI_TalonSRX rightPrimary{3};
    WPI_TalonSRX rightFollower{4};

    // SpeedControllerGroup leftMotors{leftPrimary,leftFollower};
    //SpeedControllerGroup rightMotors{rightPrimary,rightFollower};

    //DifferentialDrive differentialDrive{leftMotors,rightMotors};

    SpeedController *leftMotors;
    SpeedController *rightMotors;


};


