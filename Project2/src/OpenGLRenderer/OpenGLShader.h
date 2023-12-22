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

            virtual void SetUniformMat4(const std::string name, const glm::mat4& transform) override;
            virtual void Update(GLFWwindow* window) override;
        private:
            unsigned int m_ShaderID;
            std::string m_VertexPath;
            std::string m_FragmentPath;
            std::string m_GeometryPath;
    };
}