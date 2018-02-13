//
// Created by Jason Markham on 2/12/18.
//

#pragma once

#include <type_traits>
#include <functional>
#include <llvm/SmallVector.h>
#include <Buttons/Trigger.h>
#include <Buttons/ButtonScheduler.h>



enum class ButtonState {
    NOT_PRESSED = 0,
    PRESSED = 1 << 0,
    HELD = 1 << 1,
    RELEASED = 1 << 2,


};


constexpr ButtonState UP_STATES = static_cast<ButtonState >(
        static_cast<std::underlying_type_t<ButtonState>>(ButtonState::NOT_PRESSED)
        | static_cast<std::underlying_type_t<ButtonState>>(ButtonState::RELEASED));

constexpr ButtonState DOWN_STATES = static_cast<ButtonState >(
        static_cast<std::underlying_type_t<ButtonState>>(ButtonState::PRESSED)
        | static_cast<std::underlying_type_t<ButtonState>>(ButtonState::HELD));


template<ButtonState s>
constexpr inline bool matches(ButtonState query){
    return  (static_cast<std::underlying_type_t<ButtonState>>(query)
                   & static_cast<std::underlying_type_t<ButtonState>>(s))
                  != 0;
}
constexpr inline bool isUp(ButtonState state) {
    return matches<UP_STATES>(state);
}
constexpr inline bool isDown(ButtonState state) {
    return matches<DOWN_STATES>(state);
}
constexpr inline bool matches(ButtonState test,ButtonState testTarget) {
    return (static_cast<std::underlying_type_t<ButtonState>>(testTarget)
            & static_cast<std::underlying_type_t<ButtonState>>(test))
           != 0;
}

class Stick;
struct Btn {
    typedef std::function<void(const Stick*)> ButtonCallback;

    friend class Stick;

   // Btn(Stick& stick);

    ButtonState state;

    void on(ButtonState observeTypes, ButtonCallback&&);
    template<ButtonState state>
    void on( ButtonCallback &&cb) {
        on(state,std::forward<ButtonCallback>(cb));

    }

private:
    void update(bool newValue);
    void transition(ButtonState newState);

    llvm::SmallVector<std::pair<ButtonState,ButtonCallback>,1> callbacks;
    Stick* stick;
};

class StickDispatcher;
struct Stick {
//private:
    std::array<Btn,15> buttons;
    std::unique_ptr<StickDispatcher> dispatcher;

    int index = 0;
public:
    using IndexType = decltype(buttons)::size_type ;


    Stick();

    double getForward();

    double getTurn();

    Btn& button(IndexType i);


    void update();


};




class StickDispatcher : public frc::Trigger,public frc::ButtonScheduler{
public:
    explicit StickDispatcher(Stick& stick);

     bool Get() override;

    void Execute() override;

    Stick& stick;




};