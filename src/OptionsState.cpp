#include "OptionsState.hpp"
#include <memory>

std::unique_ptr<State, std::default_delete<State>> OptionsState::get() {
    std::unique_ptr<State, std::default_delete<State>> state(nullptr);
    OptionsState* optionsState = new OptionsState();
    state.reset(reinterpret_cast<State*>(optionsState));
    return std::move(state);
}

std::unique_ptr<State> OptionsState::clone() const {
    return std::make_unique<OptionsState>(*this);
}