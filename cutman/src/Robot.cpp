

#include <WPILib.h>
#include "RobotMap.h"
#include "Subsystems/Bucket.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Clamp.h"
#include "Subsystems/ClampTilt.h"
#include "Subsystems/UpperTilt.h"
#include "Subsystems/Winch.h"

struct Robot : TimedRobot {

	RobotMap robotMap;

    Bucket bucket{robotMap.bucketMotor,robotMap.bucketEncoder};
	Chassis chassis{robotMap.differentialDrive};
    Clamp clamp{robotMap.clampMotor,robotMap.clampEncoder};
    ClampTilt clampTilt{robotMap.clampTiltMotor,robotMap.clampTiltEncoder};
    UpperTilt upperTilt{robotMap.upperTiltMotor,robotMap.upperTiltEncoder};
    Winch winch{robotMap.winch};

    Robot(){
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
