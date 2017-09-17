#include "MainCamera.hpp"

MainCamera::MainCamera()
	: Entity(true), Camera()
{
	Camera::currentCamera = this;
	SetPosition(glm::vec3(0.f, 0.f, -3.0f));
}

void MainCamera::Tick()
{
	const float radius = 10.0f;
	glm::vec3 newPosition = getPosition();
	newPosition.x = sin(glfwGetTime()) * radius;
	newPosition.z = cos(glfwGetTime()) * radius;
	view = glm::lookAt(newPosition, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
}
