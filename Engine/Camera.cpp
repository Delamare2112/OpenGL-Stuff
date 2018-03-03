#include "Camera.hpp"
#include "CameraTransform.hpp"

Camera* Camera::currentCamera = nullptr;

Camera::Camera()
{
    transform = new(transform) CameraTransform(this);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    view = glm::mat4x4();
	currentCamera = this;
	SetFOV(45.f);
    transform->SetPosition(glm::vec3(0, 0, 0));
}

void Camera::UpdatePosition(const glm::vec3 newPosition)
{
    view = glm::lookAt(newPosition, newPosition + front, Transform::up);
}

void Camera::SetFOV(const float& newFOV)
{
	FOV = newFOV;
	projection = glm::perspective(FOV, 800.f/600.f, 0.01f, 100.f);
}

const glm::mat4 &Camera::getProjection() const
{
	return projection;
}

const glm::mat4 &Camera::getView() const
{
	return view;
}
