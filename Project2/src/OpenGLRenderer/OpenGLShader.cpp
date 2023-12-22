#include "OpenGLShader.h"

namespace IntermediateCG
{
    OpenGLShader::OpenGLShader(std::string vertexPath, std::string fragmentPath, std::string geometryPath)
    {
		m_VertexPath = vertexPath;
		m_FragmentPath = fragmentPath;
		m_GeometryPath = geometryPath;

        std::ifstream vShaderFile, fShaderFile;
	    vShaderFile.open(m_VertexPath);
	    fShaderFile.open(m_FragmentPath);

	    std::stringstream vss, fss;

	    vss << vShaderFile.rdbuf();
	    fss << fShaderFile.rdbuf();

	    vShaderFile.close();
	    fShaderFile.close();

	    std::string vString, fString;

	    vString = vss.str();
	    fString = fss.str();

	    const char* vShaderCode = vString.c_str();
	    const char* fShaderCode = fString.c_str();

	    int success;
	    char log[512];

	    unsigned int vShader;
	    vShader = glCreateShader(GL_VERTEX_SHADER);
	    glShaderSource(vShader, 1, &vShaderCode, NULL);
	    glCompileShader(vShader);
	    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	    if(!success)
	    {
	    	glGetShaderInfoLog(vShader, 512, NULL, log);
	    	std::cout << "[-] ERROR::VertexShader::Compilation" << std::endl;
	    }

	    unsigned int fShader;
	    fShader = glCreateShader(GL_FRAGMENT_SHADER);
	    glShaderSource(fShader, 1, &fShaderCode, NULL);
	    glCompileShader(fShader);
	    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	    if(!success)
	    {
	    	glGetShaderInfoLog(fShader, 512, NULL, log);
	    	std::cout << "[-] ERROR::FragmentShader::Compilation" << std::endl;
	    }

	    m_ShaderID = glCreateProgram();
	    glAttachShader(m_ShaderID, vShader);
	    glAttachShader(m_ShaderID, fShader);
	    glLinkProgram(m_ShaderID);
	    glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &success);
	    if(!success)
	    {
	    	glGetProgramInfoLog(m_ShaderID, 512, NULL, log);
	    	std::cout << "[-] ERROR::Program::Linking" << std::endl;
	    }
    }

    void OpenGLShader::Use()
    {
        glUseProgram(m_ShaderID);
    }
    
	void OpenGLShader::SetUniformMat4(const std::string name, const glm::mat4& transform)
    {
		uint32_t location = glGetUniformLocation(m_ShaderID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(transform));
    }
    
	void OpenGLShader::Update(GLFWwindow* window)
    {
		int f6Key = glfwGetKey(window, GLFW_KEY_F6);

		if(f6Key == GLFW_PRESS)
		{
			std::ifstream vShaderFile, fShaderFile;
	    	vShaderFile.open(m_VertexPath);
	    	fShaderFile.open(m_FragmentPath);

	    	std::stringstream vss, fss;

	    	vss << vShaderFile.rdbuf();
	    	fss << fShaderFile.rdbuf();

	    	vShaderFile.close();
	    	fShaderFile.close();

	    	std::string vString, fString;

	    	vString = vss.str();
	    	fString = fss.str();

	    	const char* vShaderCode = vString.c_str();
	    	const char* fShaderCode = fString.c_str();

	    	int success;
	    	char log[512];

	    	unsigned int vShader;
	    	vShader = glCreateShader(GL_VERTEX_SHADER);
	    	glShaderSource(vShader, 1, &vShaderCode, NULL);
	    	glCompileShader(vShader);
	    	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	    	if(!success)
	    	{
	    		glGetShaderInfoLog(vShader, 512, NULL, log);
	    		std::cout << "[-] ERROR::VertexShader::Compilation" << std::endl;
	    	}

	    	unsigned int fShader;
	    	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	    	glShaderSource(fShader, 1, &fShaderCode, NULL);
	    	glCompileShader(fShader);
	    	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	    	if(!success)
	    	{
	    		glGetShaderInfoLog(fShader, 512, NULL, log);
	    		std::cout << "[-] ERROR::FragmentShader::Compilation" << std::endl;
	    	}

	    	m_ShaderID = glCreateProgram();
	    	glAttachShader(m_ShaderID, vShader);
	    	glAttachShader(m_ShaderID, fShader);
	    	glLinkProgram(m_ShaderID);
	    	glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &success);
	    	if(!success)
	    	{
	    		glGetProgramInfoLog(m_ShaderID, 512, NULL, log);
	    		std::cout << "[-] ERROR::Program::Linking" << std::endl;
	    	}

			std::cout << "[+] Shader Recompilation Successful! ID(" << m_ShaderID << ")" << std::endl; 
		}
    }
}