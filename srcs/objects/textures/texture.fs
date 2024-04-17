#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float mixValue;
uniform bool useColor;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	if (useColor)
		FragColor = vec4(0.2f, 0.3f, 0.5f, 1.0f);
	else
		FragColor = mix( texture(texture1, TexCoord), texture(texture2, TexCoord), texture(texture2, TexCoord).a * mixValue);
}
