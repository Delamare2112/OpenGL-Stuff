#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform vec4 ourColor;

void main() {
    color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2) * ourColor;
}
