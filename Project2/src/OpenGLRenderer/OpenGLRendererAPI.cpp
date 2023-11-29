#include "OpenGLRendererAPI.h"

namespace IntermediateCG
{
    void OpenGLRendererAPI::Init()
    {
        glfwInit();
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    int OpenGLRendererAPI::CreateWindow(unsigned int width, unsigned int height, const char* title)
    {
        GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	    if (!window)
	    {
	    	std::cout << "Failed to create window!" << std::endl;
	    	glfwTerminate();
	    	return 0;
	    }
	    glfwMakeContextCurrent(window);

        m_Window = window;

        #ifdef API_OPENGL
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	        {
	        	std::cout << "Failed to Initialize Glad!" << std::endl;
	        	glfwTerminate();
	        	return 0;
	        }
        #endif

        return 1;
    }

    void OpenGLRendererAPI::SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRendererAPI::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::SwapBuffer()
    {
        glfwSwapBuffers(m_Window);
    }

    void OpenGLRendererAPI::PollEvents()
    {
        glfwPollEvents();
    }

    bool OpenGLRendererAPI::GetWindowShouldClose()
    {
        if(!glfwWindowShouldClose(m_Window))
            return true;
        
        return false;
    }

    void OpenGLRendererAPI::Terminate()
    {
        glfwTerminate();
    }
}