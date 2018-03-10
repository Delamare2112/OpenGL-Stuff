#pragma once

#include "Engine/Entity.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Material.h"
#include "Engine/Renderer.h"
#include <glm/gtc/matrix_transform.hpp>

class Cube : public Entity
{
private:
	static GLuint indices[];
	static GLfloat verts[];
//	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
//	GLuint VAO;
//	GLuint EBO;
//
//	int viewLoc;
//	int modelLoc;
//	int projectionLoc;

public:
	Cube();
    ~Cube() override;
//	glm::mat4 model;
	Shader* shader;
	Material material;
	Renderer* renderer;
	void Tick() override;
};
