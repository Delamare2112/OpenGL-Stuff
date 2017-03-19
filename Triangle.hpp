#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Shader.hpp"

class Triangle : public Entity
{
private:
	static GLfloat verts[];
	// GLint vertexColorLocation;
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint VAO;
	Shader shader;
public:
	Triangle();
	~Triangle();
	virtual void Tick() override;
};
