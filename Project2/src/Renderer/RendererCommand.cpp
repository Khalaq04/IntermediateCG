#include "RendererCommand.h"
#include "OpenGLRenderer/OpenGLRendererAPI.h"

namespace IntermediateCG
{
    RendererAPI* RendererCommand::s_RendererAPI = new OpenGLRendererAPI;
}