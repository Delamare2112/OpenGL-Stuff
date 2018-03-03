#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "Entity.hpp"
#include "Transform.hpp"

class Camera : public Entity
{
private:
	float FOV;
	glm::mat4 projection;

public:
	glm::mat4 view;
	glm::vec3 front;

	explicit Camera();

	static Camera* currentCamera;

	void Tick() override;

	void SetFOV(const float& newFOV);

	const glm::mat4& getProjection() const;
	const glm::mat4& getView() const;
};
