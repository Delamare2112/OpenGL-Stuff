#pragma once

#include "Engine/Entity.hpp"

class Triangle : public Entity
{
private:
	static GLfloat verts[];
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint VAO;
public:
	Triangle();
	~Triangle();
	virtual void Tick() override;
};
