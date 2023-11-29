#include "Main.h"

int main()
{
	if(m_API == IntermediateCG::RendererAPI::API::OpenGL)
		std::cout << "[+] Rendering API -> OpenGL" << std::endl;
	
	m_RendererCommand->Init();

	std::string title = "Project 2";

	m_RendererCommand->CreateWindow(1080, 720, title.c_str()); 
	
	// Shaders------------------------------------------------------------------------------------------------------
	std::ifstream vShaderFile, fShaderFile;
	vShaderFile.open("assets/shaders/Vshader.glsl");
	fShaderFile.open("assets/shaders/Fshader.glsl");

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

	unsigned int program;
	program = glCreateProgram();
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(program, 512, NULL, log);
		std::cout << "[-] ERROR::Program::Linking" << std::endl;
	}
	// ----------------------------------------------------------------------------------------------------------------

	m_VertexBuffer = IntermediateCG::VertexBuffer::Create("assets/meshes/teapot.obj", m_Vertices);
	m_VertexArray = IntermediateCG::VertexArray::Create();
	m_VertexArray->Bind();
	m_VertexBuffer->Bind();
	m_VertexArray->AddVertexBuffer(m_VertexBuffer);

	while (m_RendererCommand->GetWindowShouldClose())
	{
		m_RendererCommand->SetClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		m_RendererCommand->Clear();

		glUseProgram(program);
		glDrawArrays(GL_POINTS, 0, m_Vertices.size());

		m_RendererCommand->SwapBuffer();
		m_RendererCommand->PollEvents();
	}

	m_RendererCommand->Terminate();
	delete m_RendererCommand;
	return 0;
}