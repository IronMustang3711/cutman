//
// Created by Jason Markham on 2/12/18.
//

#pragma once

#include <Commands/Command.h>
class DelayCommand  : public frc::Command {
public:
    explicit DelayCommand(double seconds);

protected:
    bool IsFinished() override ;

};


