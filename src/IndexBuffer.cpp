#include "IndexBuffer.h"
#include "Renderer.h"
#include <cassert>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_Count(count)
{
    assert(sizeof(unsigned int) == sizeof(GLuint)) ;
    glGenBuffers(1, &m_RendererID); // create a buffer give it an id
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::Unbind() const
{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}