#include "Buffer.h"

#include "OpenGLRenderer/OpenGLBuffer.h"

namespace IntermediateCG
{
    VertexBuffer* VertexBuffer::Create(std::string filepath, std::vector<Vertex>& vertices)
    {
        std::ifstream is;
	    std::string line;

	    is.open(filepath);
	    if (!is)
	    	std::cout << "[-] Failed to open file!" << std::endl;
        else
            std::cout << "[+] File opened Successfully!" << std::endl;

		Vertex v;

	    while(std::getline(is, line))
	    {
	    	if(line[0] == 'v' && line[1] == ' ')
	    	{
	    		std::istringstream ss(line.substr(2));
	    		ss >> v.x >> std::ws >> v.y >> std::ws >> v.z;
	    		vertices.push_back(v);
	    	}
	    }
        
	    is.close();

        switch(RendererAPI::GetAPI())
        {
            case RendererAPI::API::None : std::cout << "[-] RendererAPI::None is currently not supported!" << std::endl; return nullptr;
            case RendererAPI::API::OpenGL : return new OpenGLVertexBuffer(vertices);
        }
        return nullptr;
    }

    int VertexBuffer::LoadObjMesh(std::string filepath, std::vector<Vertex>& vertices)
    {
        std::ifstream is;
	    std::string line;

	    is.open(filepath);
	    if (!is)
        {
	    	std::cout << "[-] Failed to open file!" << std::endl;
            return 0;
        }
        else
            std::cout << "[+] File opened Successfully!" << std::endl;

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
        return 1;
    }
}