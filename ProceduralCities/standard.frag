#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D textureSample;

void main()
{
	FragColor = texture(textureSample, TexCoord);
	vec4 color = texture(textureSample, TexCoord);
	if (color.w < 1) discard;
}