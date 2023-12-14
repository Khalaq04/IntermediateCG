#include "Shader.h"

#include "OpenGLRenderer/OpenGLShader.h"

namespace IntermediateCG
{
    Shader* Shader::Create(std::string vertexPath, std::string fragmentPath, std::string geometryPath)
    {
        switch(RendererAPI::GetAPI())
        {
            case RendererAPI::API::None : std::cout << "[-] RendererAPI::None is currently not supported!" << std::endl; return nullptr;
            case RendererAPI::API::OpenGL : return new OpenGLShader(vertexPath, fragmentPath, geometryPath);
        }
        return nullptr;
    }
}