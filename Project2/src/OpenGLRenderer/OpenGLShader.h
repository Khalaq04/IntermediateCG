#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Renderer/Shader.h"

namespace IntermediateCG
{
    class OpenGLShader : public Shader
    {
        public:
            OpenGLShader(std::string vertexPath, std::string fragmentPath, std::string geometryPath = std::string());
            virtual void Use() override;
        private:
            unsigned int m_ShaderID;
    };
}