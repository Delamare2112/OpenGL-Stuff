#include "Game.hpp"
#include "Entity.hpp"
#include <iostream>

GLFWwindow* Game::window = nullptr;
GameState Game::state = GameState::stopped;
std::vector<std::function<void()>> Game::Ticks;

GLFWwindow*const Game::GetWindow() { return window; }
const GameState Game::GetState() { return state; }

glslImporter::glslImporter(const std::string& s)
	: glslData(Import(s))
{ }

// Why does this almost always fail?
const char* glslImporter::Import(const std::string& path)
{
	// std::ifstream ifile(path, std::ios::in);
	// std::ostringstream glsl;
	// glsl << ifile.rdbuf();
	// std::cout << "returning: \n" << glsl.str().c_str() <<'\n';
	// return glsl.str().c_str();

	std::string data;
	std::ifstream ifile(path, std::ios::in);
	data.assign(std::istreambuf_iterator<char>(ifile), std::istreambuf_iterator<char>());
	// std::cout << "returning: \n" << data.c_str() <<'\n';
	return data.c_str();
}

glslImporter::operator const char**()
{
	return &glslData;
}

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

void Game::Exit()
{
	state = GameState::closing;
	for(Entity*& e : Entity::entities)
		delete e;
	state = GameState::stopped;
	glfwTerminate();
}
