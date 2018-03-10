#pragma once

#include "Component.hpp"
#include "Mesh.h"
#include "Material.h"

class Renderer : public Component
{
private:
//	Mesh* mesh;
//	Material* material;
public:
	explicit Renderer(Entity* owner, bool shouldTick=false);

	void Init(Mesh* mesh, Material* material);
};
