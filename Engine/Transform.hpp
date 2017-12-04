#pragma once
#include <glm/gtc/matrix_transform.hpp>

class Transform {
protected:
    glm::vec3 position;
public:
    glm::vec3 GetPosition() const;
    virtual void SetPosition(glm::vec3 newPosition);
};
