#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Renderer/Buffer.h"

namespace IntermediateCG
{
    class VertexArray
    {
        public:
            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            virtual void AddVertexBuffer(const VertexBuffer* vertexBuffer) = 0;

            static VertexArray* Create();
    };
}