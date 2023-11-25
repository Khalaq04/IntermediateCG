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

	std::ifstream is;
	std::string line;
	int cnt = 0;
	Vertex* vertices = new Vertex;
	Vertex* baseVertex = vertices;

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
			ss >> vertices->x >> std::ws >> vertices->y >> std::ws >> vertices->z;
			vertices++;
			cnt++;
		}
	}

	vertices--;
	
	is.close();

	unsigned int vertexBuffer, vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);

	glBindVertexArray(vertexArray);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices - baseVertex, baseVertex, GL_STATIC_DRAW);

	glVertexAttribPointer(0, cnt, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	while (m_RendererCommand->GetWindowShouldClose())
	{
		m_RendererCommand->SetClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		m_RendererCommand->Clear();

		glDrawArrays(GL_POINTS, 0, cnt);

		m_RendererCommand->SwapBuffer();
		m_RendererCommand->PollEvents();
	}

	glDeleteVertexArrays(1, &vertexArray);
	glDeleteBuffers(1, &vertexBuffer);
	
	m_RendererCommand->Terminate();
	delete m_RendererCommand;
	delete baseVertex;
	delete vertices;
	return 0;
}