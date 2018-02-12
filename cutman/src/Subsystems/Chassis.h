//
// Created by Jason Markham on 2/9/18.
//
#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

namespace drive_train {
    template<typename T>
    constexpr double maxOutput = 1.0;

    template<typename T>
    constexpr double quickStopThreshold = 0.2;

    template<typename T>
    constexpr double quickStopAlpha = 0.1;

    template<typename T>
    constexpr double quickStopAccumulator = 0.0;
}

template<typename Derived>
class DifferentialDriveLite {
public:
    void arcadeDrive(double speed, double rotation);

    void curvatureDrive(double fwdSpeed, double rotation, bool isQuickTurn);

protected:
    //void setLeftOutput(double output);
    //void setRightOutput(double output);


    static constexpr auto maxOut = drive_train::maxOutput<Derived>;
    static constexpr auto quickStopThreshold = drive_train::quickStopThreshold<Derived>;
    static constexpr auto quickStopAlpha = drive_train::quickStopAlpha<Derived>;
    static constexpr auto quickStopAccumulator = drive_train::quickStopAccumulator<Derived>;

};

class MyDifferentialDrive;
namespace drive_train {
    template<>
    constexpr double maxOutput<MyDifferentialDrive> = 0.8;
}

class MyDifferentialDrive : public DifferentialDriveLite<MyDifferentialDrive> {
    TalonSRX left{1};
    TalonSRX right{3};

    void setLeftOutput(double output);

    void setRightOutput(double output);

    static_assert(maxOut == 0.8, "max out");

};


class Chassis : public Subsystem {
public:
    static Chassis &getInstance();

    void arcadeDrive(double speed, double rotation);

    void curvatureDrive(double fwdSpeed, double rotation, bool isQuickTurn);

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

    SpeedController *leftMotors;
    SpeedController *rightMotors;


    double maxOutput = 1.0;
    double quickStopThreshold = kDefaultQuickStopThreshold;
    double quickStopAlpha = kDefaultQuickStopAlpha;
    double quickStopAccumulator = 0.0;

};


