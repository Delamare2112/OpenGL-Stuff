#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	float FOV;
	glm::vec3 position;
	glm::mat4 projection;
	glm::mat4 view;

public:
	Camera();

	static Camera* currentCamera;

	void SetPosition(const glm::vec3 newPosition);

	void SetFOV(const float& newFOV);

	const glm::mat4& getProjection() const;
	const glm::mat4& getView() const;
};
