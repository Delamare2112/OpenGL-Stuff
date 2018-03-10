#pragma once
#include <glm/gtc/matrix_transform.hpp>

class Transform {
public:
    static const glm::vec3 up;
    glm::vec3 position;
	glm::mat4 model;
};
