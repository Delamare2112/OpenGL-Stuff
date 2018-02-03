#include "Camera.hpp"
#include "CameraTransform.hpp"

Camera* Camera::currentCamera = nullptr;

Camera::Camera()
{
    transform = new(transform) CameraTransform(this);
	currentCamera = this;
	SetFOV(45.f);
    transform->SetPosition(glm::vec3(0, 0, 0));
}

void Camera::UpdatePosition(const glm::vec3 newPosition)
{
    view = glm::mat4x4();
    view = glm::translate(view, newPosition);
}

void Camera::SetFOV(const float& newFOV)
{
	FOV = newFOV;
	projection = glm::perspective(FOV, 800.f/600.f, 0.01f, 100.f);
}

void Camera::Tick()
{
    const float radius = 10.0f;
    glm::vec3 newPosition = transform->GetPosition();
    newPosition.x = sin(glfwGetTime()) * radius;
    newPosition.z = cos(glfwGetTime()) * radius;
    view = glm::lookAt(newPosition, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
}

const glm::mat4 &Camera::getProjection() const
{
	return projection;
}

const glm::mat4 &Camera::getView() const
{
	return view;
}
