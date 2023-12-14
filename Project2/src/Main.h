#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#ifdef API_OPENGL
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
#endif

#include "Renderer/RendererAPI.h"
#include "Renderer/RendererCommand.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"

IntermediateCG::RendererCommand* m_RendererCommand;
IntermediateCG::RendererAPI::API m_API = m_RendererCommand->s_RendererAPI->GetAPI();

std::vector<IntermediateCG::Vertex> m_Vertices;

IntermediateCG::VertexBuffer* m_VertexBuffer;
IntermediateCG::VertexArray* m_VertexArray;
IntermediateCG::Shader* m_Shader;