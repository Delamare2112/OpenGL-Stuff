#pragma once

#include <vector>
#include <functional>
#include <glm/detail/type_mat.hpp>
#include <set>

class Shader;

class Material
{
private:
    std::unordered_map<int, std::function<void(void)>> actions;
	Shader* shader;
public:
	std::set<glm::mat4*> referencedTransforms;

	Material() = default;

	void SetShader(Shader* shader);
	Shader* GetShader() const;
    void Apply();
    void SetUniform(const char* name, float x);
    void SetUniform(const char* name, float x, float y);
    void SetUniform(const char* name, float x, float y, float z);
    void SetUniform(const char* name, float x, float y, float z, float w);
    void SetUniform(const char* name, int x);
    void SetUniform(const char* name, int x, int y);
    void SetUniform(const char* name, int x, int y, int z);
    void SetUniform(const char* name, int x, int y, int z, int w);
    void SetUniform(const char* name, unsigned int x);
    void SetUniform(const char* name, unsigned int x, unsigned int y);
    void SetUniform(const char* name, unsigned int x, unsigned int y, unsigned int z);
    void SetUniform(const char* name, unsigned int x, unsigned int y, unsigned int z, unsigned int w);
};
