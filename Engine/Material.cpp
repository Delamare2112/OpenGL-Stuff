#include <GL/glew.h>
#include "Material.h"
#include "Shader.hpp"

void Material::Apply()
{
    for(auto& action : actions)
    {
        action.second();
    }
}

void Material::SetUniform(const char *name, float x)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform1f(loc, x);});
}

void Material::SetUniform(const char *name, float x, float y)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform2f(loc, x, y);});
}

void Material::SetUniform(const char *name, float x, float y, float z)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform3f(loc, x, y, z);});
}

void Material::SetUniform(const char *name, float x, float y, float z, float w)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform4f(loc, x, y, z, w);});
}

void Material::SetUniform(const char *name, int x)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform1i(loc, x);});
}

void Material::SetUniform(const char *name, int x, int y)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform2i(loc, x, y);});
}

void Material::SetUniform(const char *name, int x, int y, int z)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform3i(loc, x, y, z);});
}

void Material::SetUniform(const char *name, int x, int y, int z, int w)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform4i(loc, x, y, z, w);});
}

void Material::SetUniform(const char *name, unsigned int x)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform1ui(loc, x);});
}

void Material::SetUniform(const char *name, unsigned int x, unsigned int y)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform2ui(loc, x, y);});
}

void Material::SetUniform(const char *name, unsigned int x, unsigned int y, unsigned int z)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform3ui(loc, x, y, z);});
}

void Material::SetUniform(const char *name, unsigned int x, unsigned int y, unsigned int z, unsigned int w)
{
    const int loc = glGetUniformLocation(shader->GetProgram(), name);
    actions[loc] = ([=](){glUniform4ui(loc, x, y, z, w);});
}

void Material::SetShader(Shader* shader)
{
    this->shader = shader;
}

Shader *Material::GetShader() const
{
    return shader;
}
