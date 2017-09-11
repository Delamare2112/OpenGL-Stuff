#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Shader.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Rectangle : public Entity
{
private:
	static GLuint indices[];
	static GLfloat verts[];
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint VAO;
	GLuint EBO;
public:
	Rectangle();
	~Rectangle();
	glm::mat4 trans;
	Shader* shader;
	virtual void Tick() override;
};
