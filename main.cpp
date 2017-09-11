#include "Engine/Game.hpp"
#include "Engine/Entity.hpp"
#include <iostream>
#include <cassert>
#include "BackgroundColorChanger.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"

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

	Game::SetClearColor({0.2f, 0.3f, 0.3f, 1.f});

	// Game loop
	while(!glfwWindowShouldClose(Game::GetWindow()))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffer and fill with ClearColor
		
		Game::Tick();

		glfwSwapBuffers(Game::GetWindow());
	}
	Game::Exit();

	std::cout << "Byebye!" << std::endl;
	return 0;
}
