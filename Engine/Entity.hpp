#pragma once
#include "PackedDynamicArray.hpp"
#include "Game.hpp"

class Entity
{
private:
	size_t iid;
protected:
	Entity(bool shouldTick=false);
public:
	virtual ~Entity();
	static PackedDynamicArray<Entity*> entities;
	virtual void Tick() = 0;
};
