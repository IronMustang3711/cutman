//
// Created by Jason Markham on 2/9/18.
//

#include "SimplePIDSubsystem.h"




double SimplePIDSubsystem::ReturnPIDInput() {
    return encoder.PIDGet();
}

void SimplePIDSubsystem::UsePIDOutput(double output) {
    motor.PIDWrite(output);
}

SimplePIDSubsystem::SimplePIDSubsystem(const llvm::Twine &name, double p, double i, double d, double f, double period,
                                       frc::PIDOutput &_motor, frc::PIDSource &_encoder)
: frc::PIDSubsystem(name,p,i,d,f,period), motor{_motor},encoder{_encoder}
{

    AddChild(dynamic_cast<Sendable&>(motor));
    AddChild(dynamic_cast<Sendable&>(encoder));

    //Already done in PIDSubsystem:
   // AddChild(GetPIDController());

}


