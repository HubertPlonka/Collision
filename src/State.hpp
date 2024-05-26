#pragma once
#include <memory>

class State {
public:
    virtual ~State() {}
    virtual std::unique_ptr<State> clone() const = 0;
};