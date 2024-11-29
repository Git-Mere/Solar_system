#version 410 core

layout(location = 0) in vec3 vColor;
layout(location = 1) in vec2 vTextureCoordinates;

layout(location = 0) out vec4 fFragClr;

uniform sampler2D  uTex2d;
uniform float uUseInterpolatedColor;
uniform vec3 uColor0;
uniform vec3 uColor1;
uniform float uTileSize;
uniform float uAlpha;
uniform float uBool;

void main()
{
    vec4 interpolated_color = mix(vec4(1.0), vec4(vColor, 1.0), uUseInterpolatedColor);

    vec2 pixel = vec2(gl_FragCoord.xy);
    float tx = floor(pixel.x / uTileSize);
    float ty = floor(pixel.y / uTileSize);
    float c = mod(tx + ty, 2.0f);

    vec4 procedural_color = mix(vec4(uColor0, 1.0), vec4(uColor1, 1.0), float(c));

    vec4 texture_color = mix(texture(uTex2d, vTextureCoordinates) * vec4(1.0f, 1.0f, 1.0f, uAlpha)  ,   vec4(1), uBool);


    fFragClr = interpolated_color * procedural_color * texture_color;
}
