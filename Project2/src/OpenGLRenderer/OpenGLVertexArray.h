#pragma once
#include "Renderer/VertexArray.h"

namespace IntermediateCG
{
    class OpenGLVertexArray : public VertexArray
    {
        public:
            OpenGLVertexArray();
            ~OpenGLVertexArray();

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual void AddVertexBuffer(const VertexBuffer* vertexBuffer) override;
        private:
            unsigned int m_RendererID;
    };
}