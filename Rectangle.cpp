#include "Rectangle.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

GLfloat Rectangle::verts[] = {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, -1.0f,  // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, -1.0f   // Top Left
};

GLuint Rectangle::indices[] = {  // Note that we start from 0!
    0, 1, 3,   // First Triangle
    1, 2, 3    // Second Triangle
};

Rectangle::Rectangle()
	: Entity(true),
	shader("Engine/texVertex.glsl", "Engine/texFragment.glsl")
{
	shader.AddTexture("container.jpg", "ourTexture1");
	shader.AddTexture("awesomeface.png", "ourTexture2");

	// Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

		// Vertex Buffer Object
		glGenBuffers(1, &VBO); // gen a buffer id
		glBindBuffer(GL_ARRAY_BUFFER, VBO); // Set our VBO as the current array buffer target
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)

		// Element Array Object
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// Set attributes
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
}

void Rectangle::Tick()
{
	// Use our program
	shader.Use();

	trans = glm::rotate(trans, Game::deltaTime * glm::radians(50.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	std::cout << Game::deltaTime << std::endl;

	GLint transformLoc = glGetUniformLocation(shader.GetProgram(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0); // Make sure we don't mistakenly use our VAO elsewhere
}

Rectangle::~Rectangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
