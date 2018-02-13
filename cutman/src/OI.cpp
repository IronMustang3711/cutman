//
// Created by Jason Markham on 2/12/18.
//

#include "OI.h"
#include <DriverStation.h>
#include <Notifier.h>
#include <bitset>

double Stick::getForward() {
    return DriverStation::GetInstance().GetStickAxis(index,1);
}

double Stick::getTurn() {
       return DriverStation::GetInstance().GetStickAxis(index,3);

}



Stick::Stick()  {
    buttons.fill(Btn());
    dispatcher = std::make_unique<StickDispatcher>(*this);
    dispatcher->Start();
}

Btn &Stick::button(Stick::IndexType i) {
    return buttons.at(i);
}

void Stick::update() {
    auto& ds = DriverStation::GetInstance();

    auto rawVal = ds.GetStickButtons(index);
    std::bitset<20> bs{static_cast<unsigned long>(rawVal)};

    for (Stick::IndexType i = 0; i < buttons.size(); ++i) {
        buttons[i].update(bs[i]);
    }

}

void Btn::on(ButtonState observeTypes,  ButtonCallback &&cb) {
   callbacks.emplace_back(observeTypes,std::forward<ButtonCallback>(cb));
}


void Btn::update(bool newValue) {
    switch(state){
        case ButtonState::NOT_PRESSED:
            if(newValue) transition(ButtonState::PRESSED);
            break;

        case ButtonState::PRESSED:
            if(!newValue) transition(ButtonState::RELEASED);
            else transition(ButtonState::HELD);
            break;

        case ButtonState::HELD:
            if(!newValue) transition(ButtonState::RELEASED);
            break;

        case ButtonState::RELEASED:
            if(newValue) transition(ButtonState::PRESSED);
            else transition(ButtonState::NOT_PRESSED);
            break;
    }
}

void Btn::transition(ButtonState newState) {
    state = newState;

    for(auto& kv : callbacks){
        if(matches(kv.first,newState))
            kv.second(stick);
    }

}



//Btn::Btn(Stick &_stick) : stick{_stick}{
//
//}

bool StickDispatcher::Get() {
    return false;
}

void StickDispatcher::Execute() {
    stick.update();

}

StickDispatcher::StickDispatcher(Stick &_stick) : Trigger(), ButtonScheduler{false,this, nullptr},stick{_stick}  {

}
