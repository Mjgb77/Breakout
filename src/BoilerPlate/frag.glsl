#version 330 core

out Vector4 Color;

uniform float time;

in Vector3 ourColor;
in Vector2 TexCoord;

uniform sampler2d texture1;
uniform sampler2d texture2;
// up to 16 textures

void main(){
color = Vector4(ourColor, 0.0f);
color = Vector4(0.2f, 0.2f, 0.2f , 0.2f);

}
