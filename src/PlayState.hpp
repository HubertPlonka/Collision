#pragma once
#include <memory>
#include "State.hpp"
#include "CurrentState.hpp"

class PlayState : public State {
public:
    static std::unique_ptr<State, std::default_delete<State>> getNew();
};