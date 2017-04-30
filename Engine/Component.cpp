#include "Component.hpp"
#include "Game.hpp"

Component::Component(bool shouldTick)
{
	if(shouldTick)
		Game::Ticks.push_back([&]{this->Tick();});
}
