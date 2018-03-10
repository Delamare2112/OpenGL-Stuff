#include "Game.hpp"
#include "Entity.hpp"

GLFWwindow* Game::window = nullptr;
GameState Game::state = GameState::stopped;
std::vector<std::function<void()>> Game::Ticks;
std::unordered_map<std::string, Shader> Game::shaderLibrary;
std::unordered_map<std::string, Mesh> Game::meshLibrary;
std::unordered_map<std::string, Material> Game::materialLibrary;

GLFWwindow*const Game::GetWindow() { return window; }
const GameState Game::GetState() { return state; }

GLuint Game::currentPolyMode = GL_FILL;
GLfloat Game::previousTime = 0;
GLfloat Game::deltaTime = 0;
int Game::height = 0;
int Game::width = 0;

bool Game::Init(int width, int height)
{
	state = GameState::initing;
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Make GLFW make our window for us
	window = glfwCreateWindow(width, height, "Trev Engine v0.0.8p1", nullptr, nullptr);
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
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	Game::width = width;
	Game::height = height;

	// other init stuff
	glfwSetKeyCallback(window, KeyCallback);

	glEnable(GL_DEPTH_TEST);

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
	const auto time = (float)glfwGetTime();
	deltaTime = time - previousTime;
	previousTime = time;
	for(const auto &t : Ticks)
		t();
}

void Game::SetClearColor(const Color& newColor)
{
	glClearColor(newColor.r, newColor.b, newColor.g, newColor.a);
}

void Game::Exit()
{
	state = GameState::closing;
	for(Entity*& e : Entity::entities) {
		delete e;
	}
	state = GameState::stopped;
	glfwTerminate();
}
