#pragma once

#include <string>
#include <GL/glew.h>
#include <set>
#include "Material.h"

class Mesh
{
private:
	GLuint* indices;
	float *verts;
	GLuint VBO; // OpenGL unsigned int, Vertex Buffer Object
	GLuint VAO;
	GLuint EBO;
	bool ready;
public:
	std::set<Material*> referencedMaterials;
	uint numIndicies;

	~Mesh();

	bool Ready() const;
	bool Init(std::string path);
	void BindVerts();
};
