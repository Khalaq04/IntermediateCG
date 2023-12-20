#version 330 core

layout (location = 0) in vec3 i_Pos;

uniform mat4 u_Transform;

void main()
{
    gl_Position = u_Transform * vec4(i_Pos * 0.05, 1.0f);
}