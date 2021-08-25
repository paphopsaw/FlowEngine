#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 view;
uniform mat4 projection;
out vec3 ourColor;

void main()
{
    gl_Position = projection * vec4(aPos, 1.0);
    ourColor = aPos;
}