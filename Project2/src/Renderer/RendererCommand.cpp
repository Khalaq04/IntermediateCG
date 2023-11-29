#include "RendererCommand.h"
#include "OpenGLRenderer/OpenGLRendererAPI.h"

namespace IntermediateCG
{
    #ifdef API_OPENGL
        RendererAPI* RendererCommand::s_RendererAPI = new OpenGLRendererAPI;
    #endif
}