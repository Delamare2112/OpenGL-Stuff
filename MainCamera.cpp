
#include "MainCamera.hpp"

MainCamera::MainCamera()
	: Entity(false), Camera()
{
	Camera::currentCamera = this;
	SetPosition(glm::vec3(0.f, 0.f, -3.0f));
}

void MainCamera::Tick()
{

}
