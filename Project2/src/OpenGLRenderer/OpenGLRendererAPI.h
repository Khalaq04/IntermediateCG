#pragma once
#include <iostream>

#include "Renderer/RendererAPI.h"

namespace IntermediateCG
{
    class OpenGLRendererAPI : public RendererAPI
    {
        public:
            virtual void Init() override;
            virtual int CreateWindow(unsigned int width, unsigned int height, const char* title) override;
            virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;
            virtual void SetClearColor(float r, float g, float b, float a) override;
            virtual void Clear() override;
            virtual void DrawPoints(unsigned int first, unsigned int count) override;
            virtual GLFWwindow* GetWindow() { return m_Window; }

            virtual void SwapBuffer() override;
            virtual void PollEvents() override;
            virtual bool GetWindowShouldClose() override;
            virtual void Terminate() override;
        private:
            GLFWwindow* m_Window;
    };
}