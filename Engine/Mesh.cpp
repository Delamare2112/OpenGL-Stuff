#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>


GLfloat rawVirts[] = {
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

GLuint rawIndicies[] = {  // Note that we start from 0!
		0, 1, 3,   // First Triangle
		1, 2, 3    // Second Triangle
};


bool Mesh::Init(std::string path)
{
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "Assimp error: " << importer.GetErrorString() << '\n';
		return false;
	}
	std::string directory = path.substr(0, path.find_last_of('/'));
	aiMesh* mesh = scene->mMeshes[0];
	const unsigned int n = mesh->mNumVertices;
	delete verts;
	verts = new float[n*3];
	unsigned int vert_i = 0;
	unsigned int buff_i = 0;
	for (; vert_i < n; ++vert_i) {
		verts[buff_i++] = mesh->mVertices[vert_i].x;
		verts[buff_i++] = mesh->mVertices[vert_i].y;
		verts[buff_i++] = mesh->mVertices[vert_i].z;
	}

	delete indices;
	const uint numPerFace = mesh->mFaces[0].mNumIndices;
	const uint offset = numPerFace * sizeof(uint);
	numIndicies = mesh->mNumFaces * numPerFace;
	indices = new uint[numIndicies];
	for (uint i = 0; i < mesh->mNumFaces; i++)

//	memcpy(indices + (i * offset), mesh->mFaces[i].mIndices, offset);
		for(uint j = 0; j < mesh->mFaces[i].mNumIndices; j++)
			indices[j + (i * numPerFace)] = mesh->mFaces[i].mIndices[j];

//	verts = rawVirts;
//	indices = rawIndicies;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Vertex Buffer Object
	glGenBuffers(1, &VBO); // gen a buffer id
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Set our VBO as the current array buffer target
	glBufferData(GL_ARRAY_BUFFER, n*3*sizeof(float), verts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)
//	glBufferData(GL_ARRAY_BUFFER, sizeof(rawVirts), rawVirts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)

	// Element Array Object
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndicies*sizeof(uint), indices, GL_STATIC_DRAW);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rawIndicies), rawIndicies, GL_STATIC_DRAW);

	// Set attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	ready = true;
	return true;
}

bool Mesh::Ready() const
{
	return ready;
}

void Mesh::BindVerts()
{
	glBindVertexArray(VAO);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
