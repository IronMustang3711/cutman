//
// Created by Jason Markham on 2/12/18.
//

#include "DelayCommand.h"

bool DelayCommand::IsFinished() {
    return IsTimedOut();
}

DelayCommand::DelayCommand(double seconds) : Command("delay: "+std::to_string(seconds)+"s",seconds) {

}
