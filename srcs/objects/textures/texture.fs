#version 330 core 
out vec4 FragColor;

in vec2 Texture;
in vec3 Color;

uniform float mixValue;
uniform bool useColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;

void main()
{
	if (useColor)
		// FragColor = vec4(0.2f, 0.3f, 0.5f, 1.0f);
		// FragColor = vec4(Texture, 0.0f, 1.0f);
		FragColor = vec4(Color, 1.0f);
	else
		// FragColor = texture(texture_diffuse1, Texture);
		// FragColor = texture(texture_diffuse2, Texture);
		FragColor = mix(texture(texture_diffuse1, Texture), texture(texture_diffuse2, Texture), texture(texture_diffuse2, Texture).a * mixValue);
		// vec3 blending = abs( wNorm );
		// blending = normalize(max(blending, 0.00001));
		// float b = (blending.x + blending.y + blending.z);
		// blending /= vec3(b, b, b);
		// vec4 xaxis = texture2D( Texture, coords.yz);
		// vec4 yaxis = texture2D( Texture, coords.xz);
		// vec4 zaxis = texture2D( Texture, coords.xy);
		// projections.vec4 tex = xaxis * blending.x + xaxis * blending.y + zaxis * blending.z;
		// FragColor = texture(texture_diffuse1, Texture);
}
