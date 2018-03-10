#include "Cube.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Renderer.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

GLfloat Cube::verts[] = {
		// positions		// texture cords
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

GLuint Cube::indices[] = {  // Note that we start from 0!
    0, 1, 3,   // First Triangle
    1, 2, 3    // Second Triangle
};

Cube::Cube()
	: Entity(true)
{
//	// Vertex Array Object
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//		// Vertex Buffer Object
//		glGenBuffers(1, &VBO); // gen a buffer id
//		glBindBuffer(GL_ARRAY_BUFFER, VBO); // Set our VBO as the current array buffer target
//		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)
//
//		// Element Array Object
//		glGenBuffers(1, &EBO);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//		// Set attributes
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//		glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);

    shader = &Game::shaderLibrary["HappyColors"];
	renderer = AddComponent<Renderer>();
	renderer->Init(&Game::meshLibrary["cube"], &Game::materialLibrary["default"]);
}

void Cube::Tick()
{
//	// Use our program
//	shader->Use();
//	glBindVertexArray(VAO);
//
//	viewLoc = glGetUniformLocation(shader->GetProgram(), "view");
//	modelLoc = glGetUniformLocation(shader->GetProgram(), "model");
//	projectionLoc = glGetUniformLocation(shader->GetProgram(), "projection");
//
	transform.model = glm::rotate(transform.model, Game::deltaTime * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//
//	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(Camera::currentCamera->getView()));
//	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(Camera::currentCamera->getProjection()));
//    material.Apply();
//
////	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//	glBindVertexArray(0); // Make sure we don't mistakenly use our VAO elsewhere
}

Cube::~Cube()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
