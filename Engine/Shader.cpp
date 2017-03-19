#include <string>
#include <fstream>
#include <iostream>
// #include <experimental/filesystem> // One day...
#include "Shader.hpp"
#include "Game.hpp"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	// One day...
	// if(!std::experimental::filesystem::exists(vertexPath)) {
	// 	std::cout << "vertexPath: " << vertexPath << " does not exist.\n";
	// 	glfwSetWindowShouldClose(Game::GetWindow(), GL_TRUE);
	// }
	// if(!std::experimental::filesystem::exists(fragmentPath)) {
	// 	std::cout << "fragmentPath: " << fragmentPath << " does not exist.\n";
	// 	glfwSetWindowShouldClose(Game::GetWindow(), GL_TRUE);
	// }
	std::ifstream vertexStream(vertexPath, std::ios::in | std::ios::binary | std::ios::ate);
	std::ifstream fragmentStream(fragmentPath, std::ios::in | std::ios::binary | std::ios::ate);
	std::string vertexString, fragmentString;

	vertexString.resize(vertexStream.tellg());
	fragmentString.resize(fragmentStream.tellg());
	
	vertexStream.seekg(0, std::ios::beg);
	fragmentStream.seekg(0, std::ios::beg);

	vertexStream.read(&vertexString[0], vertexString.size());
	fragmentStream.read(&fragmentString[0], fragmentString.size());

	vertexStream.close();
	fragmentStream.close();

	program = glCreateProgram();
	GLuint vertexShader = CompileAndAttachShader(GL_VERTEX_SHADER, vertexString.c_str());
	GLuint fragmentShader = CompileAndAttachShader(GL_FRAGMENT_SHADER, fragmentString.c_str());
	glLinkProgram(program);

	GLint linkStatus;
	glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
	if(!linkStatus)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "OpenGL Error: Shader Link Error: " << infoLog << std::endl;
		glfwSetWindowShouldClose(Game::GetWindow(), GL_TRUE);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint Shader::CompileAndAttachShader(GLuint shaderType, const GLchar* source)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, 0);
	glCompileShader(shader);

	// verify shader compiled
	GLint compileStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
	if(!compileStatus)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "OpenGL Error: Shader Compile Error: " << infoLog << std::endl;
		glfwSetWindowShouldClose(Game::GetWindow(), GL_TRUE);
	}

	glAttachShader(program, shader);
	return shader;
}

const GLuint Shader::GetProgram() const
{
	return program;
}

void Shader::Use() const
{
	glUseProgram(program);
}