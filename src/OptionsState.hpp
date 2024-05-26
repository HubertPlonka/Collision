#pragma once
#include "State.hpp"

class OptionsState : public State {
public:
    static std::unique_ptr<State, std::default_delete<State>> get();
    std::unique_ptr<State> clone() const override;
};