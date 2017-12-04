#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <functional>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Shader.hpp"

struct Color
{
	float r, b, g;
	float a = 1.f;
};

enum GameState
{
	stopped,
	initing,
	running,
	closing
};

class Game
{
private:
	Game() {}
	static GLFWwindow* window;
	static GameState state;
	static GLfloat previousTime;

public:
	static GLuint currentPolyMode;
	static GLfloat deltaTime;

	static std::vector<std::function<void()>> Ticks;
	static std::unordered_map<std::string, Shader> shaderLibrary;

	static GLFWwindow*const GetWindow();
	static const GameState GetState();

	static bool Init();
	static void Tick();
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void SetClearColor(const Color& newColor);
	static void Exit();
};
