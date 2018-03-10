#include "Renderer.h"
#include "Shader.hpp"
#include "Entity.hpp"

Renderer::Renderer(Entity *owner) : Component(owner, false)
{ }

void Renderer::Init(Mesh *mesh, Material *material)
{
	material->referencedTransforms.emplace(&owner->transform.model);
	material->GetShader()->referencedMeshes.emplace(mesh);
	mesh->referencedMaterials.emplace(material);
}
