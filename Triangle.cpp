#include "Triangle.hpp"
#include <cmath>

GLfloat Triangle::verts[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

Triangle::Triangle()
	: Entity(true)
{
	// Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, /*glslImporter("defaultVertexShader.vs")*/&Game::vertexShaderSource, NULL);
	std::cout << "compiling vertex shader\n";
	glCompileShader(vertexShader);
	Game::AssertCompileCompleted(vertexShader);

	// Fragement shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, /*glslImporter("defaultFragmentShader.vs")*/&Game::fragmentShaderSource, NULL);
	std::cout << "compiling fragment shader\n";
	glCompileShader(fragmentShader);
	Game::AssertCompileCompleted(fragmentShader);

	// Linkage
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	Game::AssertLinkCompleted(shaderProgram);

	// Set references to our shader uniforms
	vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");

	// Clean (delete objects)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

		// Vertex Buffer
		glGenBuffers(1, &VBO); // gen a buffer id
		glBindBuffer(GL_ARRAY_BUFFER, VBO); // Set our VBO as the current array buffer target
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)

		// Set attributes
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void Triangle::Tick()
{
	const GLfloat greenValue = (sin(glfwGetTime()) / 2) + 0.5;

	// Use our program
	glUseProgram(shaderProgram);

	// Do some fancy shader things
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

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
