#version 410 core 
out vec4 FragColor;

in vec2 Texture;
in vec3 Color;

uniform float mixValue;
uniform float mixColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;

void main()
{
	FragColor = (mix(texture(texture_diffuse1, Texture), texture(texture_diffuse2, Texture), texture(texture_diffuse2, Texture).a * mixValue) * (1 - mixColor)) + (vec4(Color, 1.0) * mixColor);
}
