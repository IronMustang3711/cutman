

#include <WPILib.h>
#include "RobotMap.h"
#include "Subsystems/Bucket.h"
struct Robot : TimedRobot {

	RobotMap robotMap;

    Bucket bucket{robotMap.bucketMotor,robotMap.bucketEncoder};

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
