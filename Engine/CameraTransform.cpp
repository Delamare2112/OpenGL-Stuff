#include "CameraTransform.hpp"

CameraTransform::CameraTransform(Camera* camera) {
    this->camera = camera;
}

// TODO: I don't think we need CameraTransform anymore. Just have Camera::Tick calculate the view matrix.
void CameraTransform::SetPosition(glm::vec3 newPosition) {
    position = newPosition;
    camera->UpdatePosition(newPosition);
}
