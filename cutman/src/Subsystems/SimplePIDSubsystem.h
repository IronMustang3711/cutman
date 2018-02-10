#pragma once

#include <Commands/PIDSubsystem.h>
#include <SpeedController.h>
#include <Encoder.h>

#include <llvm/Twine.h>
class SimplePIDSubsystem : public frc::PIDSubsystem {
public:
    SimplePIDSubsystem(const llvm::Twine& name,
                       double p, double i, double d, double f,
                       double period,
                       frc::PIDOutput& motor, frc::PIDSource& encoder);

    double ReturnPIDInput() override;
    void UsePIDOutput(double output) override;


private:
    frc::PIDOutput& motor;
    frc::PIDSource& encoder;

};


