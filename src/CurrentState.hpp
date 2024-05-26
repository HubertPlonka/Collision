#pragma once
#include <memory>

class State;

class CurrentState
{
public:
    static std::unique_ptr<State> get();
    static void setCrntState(std::unique_ptr<State> state);
    void changeState(std::unique_ptr<State, std::default_delete<State>> state);

private:
    static std::unique_ptr<State> currentState;
};