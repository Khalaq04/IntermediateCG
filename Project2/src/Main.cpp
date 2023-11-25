#include "Main.h"

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

	is.open("assets/meshes/teapot.obj");
	if (!is)
		std::cout << "[-] Failed to open file!" << std::endl;
	else
		std::cout << "[+] FILE OPENED SUCCESSFULLY!" << std::endl;

	while(std::getline(is, line))
	{
		cnt++;
		if(line[0] == 'v' && line[1] == ' ')
		{
			std::cout << "v found at line " << cnt << std::endl;
		}
	}

	is.close();

	while (m_RendererCommand->GetWindowShouldClose())
	{
		m_RendererCommand->SetClearColor(0.2f, 0.6f, 0.8f, 1.0f);
		m_RendererCommand->Clear();

		m_RendererCommand->SwapBuffer();
		m_RendererCommand->PollEvents();
	}

	m_RendererCommand->Terminate();
	delete m_RendererCommand;
	return 0;
}