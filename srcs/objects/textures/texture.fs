#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float mixValue;
// uniform bool useColor;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	// if (useColor)
		// FragColor = vec4(1.f, 0.0f, 0.0f, 1.0f);
	// else
	FragColor = texture(texture1, TexCoord);
}
