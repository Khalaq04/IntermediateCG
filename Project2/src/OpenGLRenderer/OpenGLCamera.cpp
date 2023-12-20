#include "OpenGLCamera.h"

namespace IntermediateCG
{
    OpenGLCamera::OpenGLCamera(const glm::vec3 &position)
        : m_Position(position), m_LookAt(glm::vec3(0.0f, 0.0f, 0.0f)), m_Up(glm::vec3(0.0f, 1.0f, 0.0f)), m_Right(1.0f, 0.0f, 0.0f)
    {
        m_ViewTransform = glm::lookAt(m_Position, m_LookAt, m_Up);
        m_PerspectiveTransform = glm::perspective((float)glm::radians(m_Zoom), 1080.0f/720.0f, 0.1f, 100.0f);
    }
    
    glm::mat4 OpenGLCamera::GetTransform()
    {
        m_ViewTransform = glm::lookAt(m_Position, m_LookAt, m_Up);
        return m_PerspectiveTransform * m_ViewTransform;
    }
    
    void OpenGLCamera::Update(GLFWwindow* window)
    {
        double x, y;
        float xpos, ypos;
        int leftButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        int rightButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

        if(leftButton == GLFW_PRESS)
        {
            glfwGetCursorPos(window, &x, &y);

            xpos = static_cast<float>(x);
            ypos = static_cast<float>(y);

            if(firstMouse)
            {
                lastX = xpos;
                lastY = ypos;
                firstMouse = false;
            }

            m_Yaw += (xpos - lastX)*0.1f;
            m_Pitch += (lastY - ypos)*0.1f;

            if(m_Pitch > 89.0f)
                m_Pitch = 89.0f;
            else if(m_Pitch < -89.0f)
                m_Pitch = -89.0f;

            lastX = xpos;
            lastY = ypos;

            glm::vec3 front;
            front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
            front.y = sin(glm::radians(m_Pitch));
            front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
            m_LookAt = glm::normalize(front);
            m_Right = glm::normalize(glm::cross(m_LookAt, glm::vec3(0.0f, 1.0f, 0.0f)));  
            m_Up = glm::normalize(glm::cross(m_Right, m_LookAt));


            GetTransform();
        }        
        else if(rightButton == GLFW_PRESS)
        {
            glfwGetCursorPos(window, &x, &y);

            xpos = static_cast<float>(x);
            ypos = static_cast<float>(y);

            if(firstMouse)
            {
                lastY = ypos;
                firstMouse = false;
            }

            m_Zoom -= (lastY - ypos)*0.1f;

            if(m_Zoom < 1.0f)
                m_Zoom = 1.0f;
            else if(m_Zoom > 45.0f)
                m_Zoom = 45.0f;

            m_PerspectiveTransform = glm::perspective((float)glm::radians(m_Zoom), 1080.0f/720.0f, 0.1f, 100.0f);

            GetTransform();
        }
        else
        {
            firstMouse = true;
        }
    }
}