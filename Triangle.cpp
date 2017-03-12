#include "Triangle.hpp"

extern "C" char _binary_defaultFragmentShader_dat_start;
extern "C" char _binary_defaultVertexShader_dat_start;
const GLchar* vertexShaderSource = &_binary_defaultVertexShader_dat_start;
const GLchar* fragmentShaderSource = &_binary_defaultFragmentShader_dat_start;

GLfloat verts[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
GLuint vertexShader;
GLuint fragmentShader;
GLuint shaderProgram;
GLuint VAO;

void AssertCompileCompleted(GLuint shader)
{
	GLint compileStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
	if(!compileStatus)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "OpenGL Error: Shader Compile Error: " << infoLog << std::endl;
		glfwSetWindowShouldClose(Game::GetWindow(), GL_TRUE);
	}
}

void AssertLinkCompleted(GLuint program)
{
	GLint linkStatus;
	glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
	if(!linkStatus)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "OpenGL Error: Shader Link Error: " << infoLog << std::endl;
		glfwSetWindowShouldClose(Game::GetWindow(), GL_TRUE);
	}
}

Triangle::Triangle()
	: Entity(true)
{
	// Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, /*glslImporter("defaultVertexShader.vs")*/&vertexShaderSource, NULL);
	std::cout << "compiling vertex shader\n";
	glCompileShader(vertexShader);
	AssertCompileCompleted(vertexShader);

	// Fragement shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, /*glslImporter("defaultFragmentShader.vs")*/&fragmentShaderSource, NULL);
	std::cout << "compiling fragment shader\n";
	glCompileShader(fragmentShader);
	AssertCompileCompleted(fragmentShader);

	// Linkage
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	AssertLinkCompleted(shaderProgram);

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
	// Use our program
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0); // Make sure we don't mistakenly use our VAO elsewhere
}

Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
