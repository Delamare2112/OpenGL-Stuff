#pragma once

#include "Component.hpp"
#include "Mesh.h"
#include "Material.h"

class Renderer : public Component
{
public:
	explicit Renderer(Entity *owner);

	void Init(Mesh* mesh, Material* material);
};
