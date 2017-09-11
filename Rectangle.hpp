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


	glm::mat4 projection;
	glm::mat4 view;
	int viewLoc;
	int modelLoc;
	int projectionLoc;

public:
	Rectangle();
	~Rectangle();
	glm::mat4 model;
	Shader* shader;
	virtual void Tick() override;
};
