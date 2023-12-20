#pragma once
#include <glm/glm.hpp>

#include "Renderer/RendererAPI.h"

namespace IntermediateCG
{
    class Camera
    {
        public:
            static Camera* Create(const glm::vec3& position = glm::vec3(1.0f, 0.0f, 0.0f));

            virtual glm::mat4 GetTransform() = 0;
            virtual void Update(GLFWwindow* window) = 0;
    };
}