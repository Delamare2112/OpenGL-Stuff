#include "Mesh.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

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
	numIndicies = mesh->mNumFaces * numPerFace;
	indices = new uint[numIndicies];
	for (uint i = 0; i < mesh->mNumFaces; i++)

		for(uint j = 0; j < mesh->mFaces[i].mNumIndices; j++)
			indices[j + (i * numPerFace)] = mesh->mFaces[i].mIndices[j];

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Vertex Buffer Object
	glGenBuffers(1, &VBO); // gen a buffer id
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Set our VBO as the current array buffer target
	glBufferData(GL_ARRAY_BUFFER, n*3*sizeof(float), verts, GL_STATIC_DRAW); // copy our verts to GPU memory (our VBO)

	// Element Array Object
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndicies*sizeof(uint), indices, GL_STATIC_DRAW);

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
	delete[] verts;
	delete[] indices;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
