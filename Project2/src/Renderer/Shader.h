#pragma once
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/RendererAPI.h"

namespace IntermediateCG
{
    class Shader
    {
        public:
            virtual void Use() = 0;

            virtual void SetUniformMat4(const std::string name, const glm::mat4& transform) = 0;

            static Shader* Create(std::string vertexPath, std::string fragmentPath, std::string geometryPath = std::string());
    };
}