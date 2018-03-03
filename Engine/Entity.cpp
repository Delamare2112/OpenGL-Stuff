#include "Entity.hpp"

PackedDynamicArray<Entity*> Entity::entities;

Entity::Entity(bool shouldTick)
{
	transform = new Transform();
	if(shouldTick)
		Game::Ticks.emplace_back([&]{this->Tick();});
    entities.Add(this);
}

Entity::Entity(Transform* nondefaultTransform, bool shouldTick)
{
	transform = nondefaultTransform;
	if(shouldTick)
		Game::Ticks.emplace_back([&]{this->Tick();});
    entities.Add(this);
}

Entity::~Entity()
{
	if(Game::GetState() != GameState::closing)
		entities.RemoveAt(iid);
	delete transform;
}

void Entity::Tick() {}
