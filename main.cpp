#include "Engine/Game.hpp"
#include "Engine/Entity.hpp"
#include <iostream>
#include <cassert>
#include "BackgroundColorChanger.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "MainCamera.hpp"

int main()
{
	std::cout << "Sanity Check!\n";
	assert(Game::Init());

	Shader& happyColors = Game::shaderLibrary["HappyColors"];
	happyColors.Create("Engine/texVertex.glsl", "Engine/texFragment.glsl");
	happyColors.AddTexture("container.jpg", "ourTexture1");
	happyColors.AddTexture("awesomeface.png", "ourTexture2");

	unsigned int i = 0;
	Rectangle* rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3( 0.0f,  0.0f,  0.0f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3( 2.0f,  5.0f, -15.0f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3(-1.5f, -2.2f, -2.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3(-3.8f, -2.0f, -12.3f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3( 2.4f, -0.4f, -3.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3(-1.7f,  3.0f, -7.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3( 1.3f, -2.0f, -2.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3( 1.5f,  2.0f, -2.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3( 1.5f,  0.2f, -1.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->model = glm::translate(rect->model, glm::vec3(-1.3f,  1.0f, -1.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));

	new MainCamera();

	Game::SetClearColor({0.2f, 0.3f, 0.3f, 1.f});

	glm::vec3 camPos = Camera::currentCamera->getPosition();

	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(Camera::currentCamera->getPosition() - cameraTarget);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

	// Game loop
	while(!glfwWindowShouldClose(Game::GetWindow()))
	{
		glfwPollEvents();

		float cameraSpeed = 2.5 * Game::deltaTime; // adjust accordingly

		if (glfwGetKey(Game::GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
			camPos -= cameraSpeed * cameraFront;
		if (glfwGetKey(Game::GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
			camPos += cameraSpeed * cameraFront;
		if (glfwGetKey(Game::GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
			camPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		if (glfwGetKey(Game::GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
			camPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		Camera::currentCamera->SetPosition(camPos);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffer and fill with ClearColor
		Game::Tick();
		glfwSwapBuffers(Game::GetWindow());
	}
	Game::Exit();

	std::cout << "Byebye!" << std::endl;
	return 0;
}
