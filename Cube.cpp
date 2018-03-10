#include "Cube.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Renderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Cube::Cube()
	: Entity(true),
	  materialInstance(Game::materialLibrary["default"])
{
	renderer = AddComponent<Renderer>();
	renderer->Init(&Game::meshLibrary["cube"], &materialInstance);
}

void Cube::Tick()
{
	transform.model = glm::rotate(transform.model, Game::deltaTime * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
}
