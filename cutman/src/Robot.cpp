

#include <WPILib.h>
#include <iostream>
#include "RobotMap.h"
#include "Subsystems/Bucket.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Clamp.h"
#include "Subsystems/ClampTilt.h"
#include "Subsystems/UpperTilt.h"
#include "Subsystems/Winch.h"
#include "OI.h"

struct Robot : TimedRobot {

	RobotMap robotMap;

    Bucket bucket{robotMap.bucketMotor,robotMap.bucketEncoder};

    Chassis& chassis = Chassis::getInstance();

    Clamp clamp{robotMap.clampMotor,robotMap.clampEncoder};
    ClampTilt clampTilt{robotMap.clampTiltMotor,robotMap.clampTiltEncoder};
    UpperTilt upperTilt{robotMap.upperTiltMotor,robotMap.upperTiltEncoder};
    Winch winch{robotMap.winch};

	Stick joy;

    Robot(){
        joy.button(0).on(ButtonState::PRESSED,[this](const Stick* s){
            something();
        });

        joy.buttons[1].on<DOWN_STATES>([](const Stick* s){
            std::cout << "down" <<std::endl;
        });

    }

    void something(){
        llvm::outs() << __FUNCTION__ << "\n";
    }

	void RobotInit() override {}
	void DisabledInit() override {}
	void AutonomousInit() override {}
	void TeleopInit() override {}
	

	void RobotPeriodic() override {}
	void DisabledPeriodic() override {}
	void AutonomousPeriodic() override {}
	void TeleopPeriodic() override {}
	void TestPeriodic() override {}



};

START_ROBOT_CLASS(Robot)
