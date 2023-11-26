#include "OpenGLBuffer.h"

namespace IntermediateCG
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<Vertex>& vertices)
    {
	    glGenBuffers(1, &m_RendererID);

	    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &m_RendererID);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }

    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}