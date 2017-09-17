#pragma once

#include <glm/vec3.hpp>
#include "Engine/Entity.hpp"

class MainCamera : public Entity, public Camera
{
public:
	MainCamera();

	virtual void Tick() override;
};
