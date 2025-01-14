
#include "Renderer.h"
#include <iostream>

#define GLCall(x) GLClearError();\
    x;\
    assert((GLLogCall(#x, __FILE__, __LINE__)))

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR); // clear all errors
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError()) // while we have errors we are retrieving
    {
        std::cout << "[OPENGL ERROR]" << error   << " " << function
        << " " << file << " " << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}