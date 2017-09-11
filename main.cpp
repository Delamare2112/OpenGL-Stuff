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

	Rectangle* rect = new Rectangle;
	rect->shader = &happyColors;
	rect = new Rectangle;
	rect->shader = &happyColors;
	rect->trans = glm::translate(rect->trans, glm::vec3(-1.f, 1.f, 0.0f));

	Game::SetClearColor({0.2f, 0.3f, 0.3f, 1.f});

	// Game loop
	while(!glfwWindowShouldClose(Game::GetWindow()))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT); // Clear buffer and fill with ClearColor
		
		Game::Tick();

		glfwSwapBuffers(Game::GetWindow());
	}
	Game::Exit();

	std::cout << "Byebye!" << std::endl;
	return 0;
}
