#pragma once

#include "Component.hpp"
#include "Mesh.hpp"
#include "Material.hpp"

class Renderer : public Component
{
public:
	explicit Renderer(Entity *owner);

	void Init(Mesh* mesh, Material* material);
};
