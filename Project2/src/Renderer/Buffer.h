#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Renderer/RendererAPI.h"

namespace IntermediateCG
{
    class Vertex
    {
    	public:
    		float x, y, z;
    };

    class VertexBuffer
    {
        public:            
            virtual int LoadObjMesh(std::string filepath, std::vector<Vertex>& vertices);

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            static VertexBuffer* Create(std::string filepath, std::vector<Vertex>& vertices);
    };
}