#include "Transform.hpp"

const glm::vec3 Transform::up = glm::vec3(0.0f, 1.0f, 0.0f);

glm::vec3 Transform::GetPosition() const {
    return position;
}

void Transform::SetPosition(glm::vec3 newPosition) {
    position = newPosition;
}