#pragma once
class Entity;

class Component
{
protected:
    Entity* owner;
	Component(Entity* owner, bool shouldTick=false);
public:
	virtual void Tick();
};
