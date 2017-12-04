#pragma once
#include "Transform.hpp"
#include "Camera.hpp"

class CameraTransform : public Transform {
private:
    Camera* camera;
public:
    CameraTransform(Camera* camera);
    void SetPosition(glm::vec3 newPosition) override;
};
