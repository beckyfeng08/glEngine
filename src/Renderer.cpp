
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
