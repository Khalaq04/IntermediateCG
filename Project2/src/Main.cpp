#include "Main.h"

class Vertex
{
	public:
		float x, y, z;
};

int main()
{
	if(m_API == IntermediateCG::RendererAPI::API::OpenGL)
		std::cout << "[+] Rendering API -> OpenGL" << std::endl;
	
	m_RendererCommand->Init();

	std::string title = "Project 2";

	m_RendererCommand->CreateWindow(1080, 720, title.c_str()); 

	m_RendererCommand->GladInit();

	// Loading mesh--------------------------------------------------------------------------------------------------
	std::ifstream is;
	std::string line;
	std::vector<Vertex> vertices;

	is.open("assets/meshes/teapot.obj");
	if (!is)
		std::cout << "[-] Failed to open file!" << std::endl;
	else
		std::cout << "[+] FILE OPENED SUCCESSFULLY!" << std::endl;

	while(std::getline(is, line))
	{
		if(line[0] == 'v' && line[1] == ' ')
		{
			std::istringstream ss(line.substr(2));
			Vertex v;
			ss >> v.x >> std::ws >> v.y >> std::ws >> v.z;
			vertices.push_back(v);
		}
	}
	
	is.close();
	// -------------------------------------------------------------------------------------------------------------

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

	// VAO and VBO-----------------------------------------------------------------------------------------------------
	unsigned int vertexBuffer, vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);

	glBindVertexArray(vertexArray);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	// -----------------------------------------------------------------------------------------------------------

	while (m_RendererCommand->GetWindowShouldClose())
	{
		m_RendererCommand->SetClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		m_RendererCommand->Clear();

		glUseProgram(program);
		glDrawArrays(GL_POINTS, 0, vertices.size());

		m_RendererCommand->SwapBuffer();
		m_RendererCommand->PollEvents();
	}

	// Clean up-------------------------------------------------------------------------------------------------------
	glDeleteVertexArrays(1, &vertexArray);
	glDeleteBuffers(1, &vertexBuffer);
	// ---------------------------------------------------------------------------------------------------------------
	
	m_RendererCommand->Terminate();
	delete m_RendererCommand;
	return 0;
}