#pragma once
#include <string>

#include "Renderer/RendererAPI.h"

namespace IntermediateCG
{
    class Shader
    {
        public:
            virtual void Use() = 0;

            static Shader* Create(std::string vertexPath, std::string fragmentPath, std::string geometryPath = std::string());
    };
}