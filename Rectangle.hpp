#pragma once

#include "Engine/Entity.hpp"

class Rectangle : public Entity
{
private:
	static GLuint indices[];
	static GLfloat verts[];
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint VAO;
	GLuint EBO;
public:
	Rectangle();
	~Rectangle();
	virtual void Tick() override;
};
