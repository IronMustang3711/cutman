//
// Created by Jason Markham on 2/9/18.
//
#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

//TODO: this is kind of dumb and clunky. clean up
//namespace DifferentialDriveValues {
    template<typename T>
    struct MaxOutput {
         static constexpr double value = 1.0;
    };
//template<typename T> constexpr double MaxOutput<T>::value = 1.0;
//template<typename T> double MaxOutput<T>::value = 1.0;

    template<typename T>
    struct QuickStopThreshold {
        static constexpr double value = 0.2;
    };
    template<typename T>
    struct QuickStopAlpha {
        static constexpr double value = 0.1;
    };
    template<typename T>
    struct quickStopAccumulator {
        static constexpr double value = 0.0;
    };
//}

template <typename Derived>
class DifferentialDriveLite{
public:
    void arcadeDrive(double speed,double rotation);
    void curvatureDrive(double fwdSpeed,double rotation,bool isQuickTurn);

protected:
    //void setLeftOutput(double output);
    //void setRightOutput(double output);


//private:
    using maxOutput = MaxOutput<Derived>;
    using quickStopThreshold = QuickStopThreshold<Derived>;
    using quickStopAlpha = QuickStopAlpha<Derived>;
    using quickstopAccumulator = quickStopAccumulator<Derived>;

};



class MyDifferentialDrive : public DifferentialDriveLite<MyDifferentialDrive> {
    TalonSRX left{1};
    TalonSRX right{3};
    void setLeftOutput(double output);
    void setRightOutput(double output);

//    static_assert(maxOutput::value == 0.8,"max out");
};

//template<> double MaxOutput<MyDifferentialDrive>::value = 0.8;

//template<>
//constexpr double DifferentialDriveValues::MaxOutput<MyDifferentialDrive>::value = 0.8;

    template<>
    struct MaxOutput<MyDifferentialDrive> {
        static constexpr double value = 0.8;
    };




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


