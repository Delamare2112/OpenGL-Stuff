#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Renderer.hpp"

class Cube : public Entity
{
private:
	Renderer* renderer;
public:
	Cube();
	void Tick() override;
};
