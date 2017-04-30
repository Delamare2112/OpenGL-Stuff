#include "Entity.hpp"

PackedDynamicArray<Entity*> Entity::entities;

Entity::Entity(bool shouldTick)
{
	if(shouldTick)
		Game::Ticks.push_back([&]{this->Tick();});
}

Entity::~Entity()
{
	if(Game::GetState() != GameState::closing)
		entities.RemoveAt(iid);
}
