#pragma once

class Component
{
protected:
	Component(bool shouldTick=false);
public:
	virtual void Tick() = 0;
};
