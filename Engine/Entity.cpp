#include "Entity.hpp"

PackedDynamicArray<Entity*> Entity::entities;

Entity::Entity(bool shouldTick)
{
	if(shouldTick)
		Game::Ticks.emplace_back([&]{this->Tick();});
    entities.Add(this);
}

Entity::~Entity()
{
	for (Component* component : components)
		delete component;
	if(Game::GetState() != GameState::closing)
		entities.RemoveAt(iid);
}

void Entity::Tick() {}
