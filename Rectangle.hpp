#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Shader.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Rectangle : public Entity
{
private:
	Shader shader;
	static GLuint indices[];
	static GLfloat verts[];
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint VAO;
	GLuint EBO;
	glm::mat4 trans;
public:
	Rectangle();
	~Rectangle();
	virtual void Tick() override;
};
