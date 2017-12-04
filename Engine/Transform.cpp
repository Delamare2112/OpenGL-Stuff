#include "Transform.hpp"

glm::vec3 Transform::GetPosition() const {
    return position;
}

void Transform::SetPosition(glm::vec3 newPosition) {
    position = newPosition;
}