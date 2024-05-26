#pragma once

class State 
{
public:
	virtual ~State() = default;
	virtual void update() = 0;
};