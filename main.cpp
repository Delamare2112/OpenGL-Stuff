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

	new Rectangle;
//	new Triangle;
//	new BackgroundColorChanger;
//	Rectangle* otherRect = new Rectangle;
//	otherRect->position =

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
