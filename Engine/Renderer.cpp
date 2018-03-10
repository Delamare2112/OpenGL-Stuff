//
// Created by delamare on 3/9/18.
//

#include "Renderer.h"
#include "Shader.hpp"
#include "Entity.hpp"

Renderer::Renderer(Entity *owner, bool shouldTick) : Component(owner, shouldTick)
{ }

void Renderer::Init(Mesh *mesh, Material *material)
{
	material->referencedTransforms.emplace(&owner->transform.model);
	material->GetShader()->referencedMeshes.emplace(mesh);
	mesh->referencedMaterials.emplace(material);
}
