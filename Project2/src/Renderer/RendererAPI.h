#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace IntermediateCG
{
    class RendererAPI
    {
        public:
            enum class API
            {
                None = 0, OpenGL = 1
            };

            virtual void Init() = 0;
            virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;
            virtual void SetClearColor(float r, float g, float b, float a) = 0;
            virtual void Clear() = 0;
            virtual int CreateWindow(unsigned int width, unsigned int height, const char* title) = 0;
            virtual GLFWwindow* GetWindow() = 0;

            // GLFW OpenGL
            virtual void SwapBuffer() {}
            virtual void PollEvents() {}
            virtual int GladInit() { return 0; }
            virtual bool GetWindowShouldClose() { return false; }
            virtual void Terminate() {}

            inline static API GetAPI() { return s_API; }
        private:
            static API s_API;
    };
}