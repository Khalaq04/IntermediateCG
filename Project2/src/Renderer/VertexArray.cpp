#include "VertexArray.h"

#include "OpenGLRenderer/OpenGLVertexArray.h"

namespace IntermediateCG
{
    VertexArray* VertexArray::Create()
    {
        switch(RendererAPI::GetAPI())
        {
            case RendererAPI::API::None : std::cout << "[-] RendererAPI::None is currently not supported!" << std::endl; return nullptr;
            case RendererAPI::API::OpenGL : return new OpenGLVertexArray();
        }
        return nullptr;
    }
}