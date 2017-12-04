#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Shader.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Cube : public Entity
{
private:
	static GLuint indices[];
	static GLfloat verts[];
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint VAO;
	GLuint EBO;


	int viewLoc;
	int modelLoc;
	int projectionLoc;

public:
	Cube();
	virtual ~Cube();
	glm::mat4 model;
	Shader* shader;
	void Tick() override;
};
