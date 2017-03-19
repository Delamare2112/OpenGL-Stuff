#include "Rectangle.hpp"

GLfloat Rectangle::verts[] = {
     0.5f,  0.5f, 0.0f,  // Top Right
     0.5f, -0.5f, 0.0f,  // Bottom Right
    -0.5f, -0.5f, 0.0f,  // Bottom Left
    -0.5f,  0.5f, 0.0f   // Top Left 
};

GLuint Rectangle::indices[] = {  // Note that we start from 0!
    0, 1, 3,   // First Triangle
    1, 2, 3    // Second Triangle
};

Rectangle::Rectangle()
	: Entity(true),
	shader("Engine/defaultVertexShader.glsl", "Engine/defaultFragmentShader.glsl")
{
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
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void Rectangle::Tick()
{
	// Use our program
	glUseProgram(shader.GetProgram());
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
