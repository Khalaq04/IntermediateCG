#pragma once

#include "Renderer/Buffer.h"

namespace IntermediateCG
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
        public:
            OpenGLVertexBuffer(std::vector<Vertex>& vertices);
            ~OpenGLVertexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;
        private:
            unsigned int m_RendererID;
    };
}