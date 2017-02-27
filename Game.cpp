#include "Game.hpp"
#include <iostream>

GLFWwindow* Game::window = nullptr;
std::vector<std::function<void()>> Game::Ticks;

GLFWwindow*const Game::GetWindow() { return window; }

bool Game::Init()
{
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Make GLFW make our window for us
	window = glfwCreateWindow(800, 600, "Learnin OpenGL", nullptr, nullptr);
	if(window == nullptr)
	{
		std::cout << "Failed to create GLFW window!!!\n";
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	// Get GLEW to setup our func pointers to the ones supplied by the OS's current video driver
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK)
	{
		std::cout << "GLEW has failed us...\n";
		return false;
	}

	// Viewport setup
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	return true;
}

void Game::Tick()
{
	for(auto t : Ticks)
		t();
}

void Game::SetClearColor(const Color& newColor)
{
	glClearColor(newColor.r, newColor.b, newColor.g, newColor.a);
}
