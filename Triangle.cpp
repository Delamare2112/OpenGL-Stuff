#include "Triangle.hpp"
#include <cmath>

GLfloat Triangle::verts[] = {
    // Positions         // Colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // Bottom Right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // Bottom Left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // Top 
};

Triangle::Triangle()
	: Entity(true),
	shader("Engine/coloredVertexShader.glsl", "Engine/coloredFragmentShader.glsl")
{
	// Set references to our shader uniforms
	// vertexColorLocation = glGetUniformLocation(shader.GetProgram(), "ourColor");

	// Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

		// Vertex Buffer
		glGenBuffers(1, &VBO); // gen a buffer id
		glBindBuffer(GL_ARRAY_BUFFER, VBO); // Set our VBO as the current array buffer target
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)

		// Set attributes
		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		// Color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Triangle::Tick()
{
	const GLfloat greenValue = (sin(glfwGetTime()) / 2) + 0.5;

	// Use our program
	glUseProgram(shader.GetProgram());

	// Do some fancy shader things
	// glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	//Draw
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// End
	glBindVertexArray(0); // Make sure we don't mistakenly use our VAO elsewhere
}

Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
