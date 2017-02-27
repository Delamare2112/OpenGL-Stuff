#include "Game.hpp"
#include <iostream>
#include <cassert>
#include "BackgroundColorChanger.hpp"

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	std::cout << "Sanity Check!\n";
	assert(Game::Init());

	glfwSetKeyCallback(Game::GetWindow(), KeyCallback);

	BackgroundColorChanger bcc;

	// Game loop
	while(!glfwWindowShouldClose(Game::GetWindow()))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT); // Clear buffer and fill with ClearColor
		
		Game::Tick();

		glfwSwapBuffers(Game::GetWindow());
	}

	glfwTerminate();
	std::cout << "Byebye!" << std::endl;
	return 0;
}
