#include "RendererAPI.h"

namespace IntermediateCG
{
    #ifdef API_OPENGL
        RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
    #endif
}