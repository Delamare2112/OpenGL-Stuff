#pragma once
class Entity;

class Component
{
protected:
    Entity* owner;

	explicit Component(Entity* owner, bool shouldTick=false);

public:
	virtual void Tick();
};
