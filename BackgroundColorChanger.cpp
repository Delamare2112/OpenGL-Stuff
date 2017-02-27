#include "BackgroundColorChanger.hpp"

BackgroundColorChanger::BackgroundColorChanger()
	: Entity(true)
{
	clearColor = {0.2f, 0.3f, 0.3f, 1.f};
}

void BackgroundColorChanger::Tick()
{
	Game::SetClearColor(clearColor);
	clearColor.r = clearColor.r >= 1 ? 0 : clearColor.r + 0.01f;
}
