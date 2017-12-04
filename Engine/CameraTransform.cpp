#include "CameraTransform.hpp"

CameraTransform::CameraTransform(Camera* camera) {
    this->camera = camera;
}

void CameraTransform::SetPosition(glm::vec3 newPosition) {
    position = newPosition;
    camera->UpdatePosition(newPosition);
}
