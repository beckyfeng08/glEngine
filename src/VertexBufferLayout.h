#pragma once
#include <vector>
#include "GL/glew.h"
#include "Renderer.h"
#include <stdexcept>
struct VertexBufferElement
{
    unsigned int count;
    unsigned int type;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        // assert(false);
        return 0;
    }
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout()
        : m_Stride(0) {}

    template<typename T>
    void Push(unsigned int count)
    {
        std::runtime_error("false");
    }

    template<>
    void Push<float>(unsigned int count)
    {
        VertexBufferElement v = { count, GL_FLOAT, GL_FALSE };
        m_Elements.push_back(v);
        m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
    }

    template<>
    void Push<unsigned int>(unsigned int count)
    {
        VertexBufferElement v = { count, GL_UNSIGNED_INT,  GL_FALSE };
        m_Elements.push_back(v);
        m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;

    }

    template<>
    void Push<unsigned char>(unsigned int count)
    {
        VertexBufferElement v = { count, GL_UNSIGNED_BYTE, GL_TRUE };
        m_Elements.push_back(v);
        m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;

    }

    inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
    inline unsigned int GetStride() const { return m_Stride; }

};