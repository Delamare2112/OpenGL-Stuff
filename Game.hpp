#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <functional>

struct Color
{
	float r, b, g;
	float a = 1.f;
};

class Game
{
private:
	Game() {}
	static GLFWwindow* window;

public:
	static std::vector<std::function<void()>> Ticks;

	static GLFWwindow*const GetWindow();
	static bool Init();
	static void Tick();
	static void SetClearColor(const Color& newColor);
};
