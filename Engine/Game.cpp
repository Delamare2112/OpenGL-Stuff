#include "Game.hpp"
#include "Entity.hpp"
#include <iostream>

GLFWwindow* Game::window = nullptr;
GameState Game::state = GameState::stopped;
std::vector<std::function<void()>> Game::Ticks;

GLFWwindow*const Game::GetWindow() { return window; }
const GameState Game::GetState() { return state; }

GLuint Game::currentPolyMode = GL_FILL;

bool Game::Init()
{
	state = GameState::initing;
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

	// other init stuff
	glfwSetKeyCallback(window, KeyCallback);

	return true;
}

void Game::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(action == GLFW_PRESS)
	{
		switch(key)
		{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);break;
		case GLFW_KEY_F9:
			currentPolyMode = currentPolyMode >= GL_FILL ? GL_POINT : currentPolyMode+1;
			glPolygonMode(GL_FRONT_AND_BACK, currentPolyMode);break;
		}
	}
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

void Game::Exit()
{
	state = GameState::closing;
	for(Entity*& e : Entity::entities)
		delete e;
	state = GameState::stopped;
	glfwTerminate();
}
