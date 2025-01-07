#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_RendererID));

}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    GLCall(Bind());
    GLCall(vb.Bind());
    GLCall(const auto& elements = layout.GetElements());
    GLCall(unsigned int offset = 0);
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        GLCall(const auto& element = elements[i]);
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type,
            element.normalized, layout.GetStride(), (const void*)offset));
       GLCall(offset += VertexBufferElement::GetSizeOfType(element.type) * element.count);

    }
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));

}
