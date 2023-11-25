#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer/RendererAPI.h"
#include "Renderer/RendererCommand.h"

IntermediateCG::RendererCommand* m_RendererCommand;
IntermediateCG::RendererAPI::API m_API = m_RendererCommand->s_RendererAPI->GetAPI();