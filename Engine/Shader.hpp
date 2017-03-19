#pragma once
#include <GL/glew.h>

class Shader
{
private:
	GLuint CompileAndAttachShader(GLuint shaderType, const GLchar* source);
	GLuint program;
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	const GLuint GetProgram() const;
	void Use() const;
};
