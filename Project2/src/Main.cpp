#include "Main.h"

int main()
{
	if(m_API == IntermediateCG::RendererAPI::API::OpenGL)
		std::cout << "[+] Rendering API -> OpenGL" << std::endl;

	m_RendererCommand->Init();
	std::string title = "Project 2";
	m_RendererCommand->CreateWindow(1080, 720, title.c_str());

	m_Camera = IntermediateCG::Camera::Create({0.0f, 0.0f, 0.0f});

	m_Shader = IntermediateCG::Shader::Create("assets/shaders/Vshader.glsl", "assets/shaders/Fshader.glsl");

	m_VertexBuffer = IntermediateCG::VertexBuffer::Create("assets/meshes/teapot.obj", m_Vertices);
	m_VertexArray = IntermediateCG::VertexArray::Create();
	m_VertexArray->Bind();
	m_VertexBuffer->Bind();
	m_VertexArray->AddVertexBuffer(m_VertexBuffer);

	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)) * glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	while (m_RendererCommand->GetWindowShouldClose())
	{
		m_RendererCommand->SetClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		m_RendererCommand->Clear();

		m_Camera->Update(m_RendererCommand->GetWindow());

		m_Shader->Use();
		m_Shader->SetUniformMat4("u_Transform", m_Camera->GetTransform()*model);
		m_RendererCommand->DrawPoints(0, m_Vertices.size());

		m_Shader->Update(m_RendererCommand->GetWindow());

		m_RendererCommand->SwapBuffer();
		m_RendererCommand->PollEvents();
	}

	m_RendererCommand->Terminate();
	return 0;
}