#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Shader.hpp"

class Rectangle : public Entity
{
private:
	Shader shader;
	static GLuint indices[];
	static GLfloat verts[];
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint VAO;
	GLuint EBO;
	GLuint texture1;
	GLuint texture2;
public:
	Rectangle();
	~Rectangle();
	virtual void Tick() override;
};
