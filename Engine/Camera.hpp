#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	float FOV;
	glm::vec3 position;
	glm::mat4 projection;

public:
	glm::mat4 view;

	Camera();

	static Camera* currentCamera;

	void SetPosition(const glm::vec3 newPosition);
	void SetFOV(const float& newFOV);
	glm::vec3* getPositionReference(); // Only use when PLANNING to not modify the view upon modification.
		// TODO: make position public once we have separate render tick and can make sure camera is first to be called.

	const glm::vec3& getPosition() const;
	const glm::mat4& getProjection() const;
	const glm::mat4& getView() const;
};
