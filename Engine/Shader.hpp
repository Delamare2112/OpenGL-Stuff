#pragma once
#include <GL/glew.h>
#include <vector>

class Shader
{
private:
	GLuint CompileAndAttachShader(GLuint shaderType, const GLchar* source);
	GLuint program;
	std::vector<std::pair<GLuint, const GLchar*>> textures;
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void AddTexture(const GLchar* imagePath, const GLchar* uniformString);
	void ActivateTextures() const;
	const GLuint GetProgram() const;
	void Use() const;
};
