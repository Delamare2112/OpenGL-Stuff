#include "Camera.hpp"

Camera* Camera::currentCamera = nullptr;

Camera::Camera()
{
	currentCamera = this;
	SetFOV(45.f);
	SetPosition(glm::vec3(0, 0, 0));
}

void Camera::SetPosition(const glm::vec3 newPosition)
{
	position = newPosition;
	view = glm::translate(view, position);
}

void Camera::SetFOV(const float& newFOV)
{
	FOV = newFOV;
	projection = glm::perspective(FOV, 800.f/600.f, 0.01f, 100.f);
}

const glm::vec3& Camera::getPosition() const
{
	return position;
}

const glm::mat4 &Camera::getProjection() const
{
	return projection;
}

const glm::mat4 &Camera::getView() const
{
	return view;
}
