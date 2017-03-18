#include "Game.hpp"
#include "Entity.hpp"
#include <iostream>
#include <cassert>
#include "BackgroundColorChanger.hpp"
#include "Rectangle.hpp"

int main()
{
	std::cout << "Sanity Check!\n";
	assert(Game::Init());

	// new Triangle;
	new Rectangle;
	new BackgroundColorChanger;

	std::cout << GL_POINT << " " << GL_LINE << " " << GL_FILL << '\n';

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
