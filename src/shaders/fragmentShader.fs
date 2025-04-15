#version 330 core

in vec2 texPos;
in vec3 outColor;

out vec4 FragColor;
uniform sampler2D tex;
void main()
{
    FragColor = texture(tex, texPos);
}