#include "Component.hpp"
#include "Entity.hpp"

Component::Component(Entity* owner, bool shouldTick)
{
    this->owner = owner;
	if(shouldTick)
		Game::Ticks.emplace_back([&]{this->Tick();});
}

void Component::Tick() {}
