#pragma once
#include <glm/gtc/matrix_transform.hpp>

class Transform {
protected:
    glm::vec3 position;
public:
    static const glm::vec3 up;

    glm::vec3 GetPosition() const;
    virtual void SetPosition(glm::vec3 newPosition);
};
