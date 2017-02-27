#include "Entity.hpp"

PackedDynamicArray<Entity*> Entity::entities;

Entity::Entity(bool shouldTick)
{
	iid = entities.Add(this);
	if(shouldTick)
		Game::Ticks.push_back([&]{this->Tick();});
}
