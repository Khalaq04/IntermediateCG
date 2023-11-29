#pragma once

#include "RendererAPI.h"

namespace IntermediateCG
{
    class RendererCommand
    {
        public:
            inline void Init()
            {
                s_RendererAPI->Init();
            }

            inline void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
            {
                s_RendererAPI->SetViewport(x, y, width, height);
            }

            inline void SetClearColor(float r, float g, float b, float a)
            {
                s_RendererAPI->SetClearColor(r, g, b, a);
            }

            inline void Clear()
            {
                s_RendererAPI->Clear();
            }

            inline int CreateWindow(unsigned int width, unsigned int height, const char* title)
            {
                return s_RendererAPI->CreateWindow(width, height, title);
            }

            #ifdef API_OPENGL
                inline void SwapBuffer()
                {
                    s_RendererAPI->SwapBuffer();
                }

                inline void PollEvents()
                {
                    s_RendererAPI->PollEvents();
                }

                inline bool GetWindowShouldClose()
                {
                    return s_RendererAPI->GetWindowShouldClose();
                }

                inline void Terminate()
                {
                    s_RendererAPI->Terminate();
                }

                inline GLFWwindow* GetWindow()
                {
                    s_RendererAPI->GetWindow();
                }
            #endif

            static RendererAPI* s_RendererAPI;
    };
}