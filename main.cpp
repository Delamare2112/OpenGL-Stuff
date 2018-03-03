#include "Engine/Game.hpp"
#include "Engine/Entity.hpp"
#include <iostream>
#include <cassert>
#include "BackgroundColorChanger.hpp"
#include "Triangle.hpp"
#include "Cube.hpp"
#include "Engine/Camera.hpp"
#include "FPSInput.h"

int main()
{
	std::cout << "Sanity Check!\n";
	assert(Game::Init(800, 600));

	Shader& happyBox = Game::shaderLibrary["HappyColors"]; // Make new shader called HappyColors
	happyBox.Create("Engine/texVertex.glsl", "Engine/texFragment.glsl"); // Create the new shader
	happyBox.AddTexture("container.jpg", "ourTexture1"); // Add some textures
	happyBox.AddTexture("awesomeface.png", "ourTexture2");

	unsigned int i = 0;
	auto* rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3( 0.0f,  0.0f,  0.0f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3( 2.0f,  5.0f, -15.0f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3(-1.5f, -2.2f, -2.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3(-3.8f, -2.0f, -12.3f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3( 2.4f, -0.4f, -3.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3(-1.7f,  3.0f, -7.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3( 1.3f, -2.0f, -2.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3( 1.5f,  2.0f, -2.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3( 1.5f,  0.2f, -1.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i++), glm::vec3(1.f, 0.3f, 0.5f));
	rect = new Cube;
	rect->shader = &happyBox;
	rect->model = glm::translate(rect->model, glm::vec3(-1.3f,  1.0f, -1.5f));
	rect->model = glm::rotate(rect->model, glm::radians(20.f * i), glm::vec3(1.f, 0.3f, 0.5f));

    (new Camera())->transform.position = (glm::vec3(0.f, 0.f, 3.f));

	Game::SetClearColor({0.2f, 0.3f, 0.3f, 1.f});

	FPSInput input;
	input.movementSpeed = 2.5f;
	input.mouseSensitivity = 0.1f;

	// Game loop
	while(!glfwWindowShouldClose(Game::GetWindow()))
	{
		input.Tick();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffer and fill with ClearColor
		Game::Tick();
		glfwSwapBuffers(Game::GetWindow());
	}
	Game::Exit();

	std::cout << "Byebye!" << std::endl;
	return 0;
}
