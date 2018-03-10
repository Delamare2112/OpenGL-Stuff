#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Renderer.hpp"

class Cube : public Entity
{
private:
	Renderer* renderer;
public:
	Material materialInstance;
	Cube();
	void Tick() override;
};
