#pragma once
#include "Renderer/Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

namespace IntermediateCG
{
    class OpenGLCamera : public Camera
    {
        public:
            OpenGLCamera(const glm::vec3& position = glm::vec3(1.0f, 0.0f, 0.0f));

            virtual glm::mat4 GetTransform() override;
            virtual void Update(GLFWwindow* window) override;
        private:
            glm::vec3 m_Position;
            glm::vec3 m_LookAt;
            glm::vec3 m_Up;
            glm::vec3 m_Right;

            bool firstMouse = true;
            bool isPerspective = true;

            float m_Yaw = -89.0f, m_Pitch = 0.0f; 

            double lastX = 0.0, lastY = 0.0, m_Zoom = 45.0f;

            glm::mat4 m_FinalTransform;
            glm::mat4 m_ViewTransform;

            GLFWwindow* m_Window;
    };
}