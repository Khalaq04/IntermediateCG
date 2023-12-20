#include "Camera.h"

#include "OpenGLRenderer/OpenGLCamera.h"

namespace IntermediateCG
{
    Camera *Camera::Create(const glm::vec3 &position)
    {
        switch(RendererAPI::GetAPI())
        {
            case RendererAPI::API::None : std::cout << "[-] RendererAPI::None is currently not supported!" << std::endl; return nullptr;
            case RendererAPI::API::OpenGL : return new OpenGLCamera(position);
        }
        return nullptr;
    }
}