#pragma once

#include <vector>
#include <functional>
#include "Shader.hpp"

class Material
{
private:
    std::unordered_map<int, std::function<void(void)>> actions;
public:
    uint shader;
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
