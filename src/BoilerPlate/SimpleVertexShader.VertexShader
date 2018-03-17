#version 330 core


layout (location = 0) in Vector3 aPos;
layout (location = 1) in Vector3 aColor;
layout (location = 2) in Vector2 aTexCoord;

uniform Matrix4 model;
uniform Matrix4 view;
uniform Matrix4 projection;


out Vector3 ourColor;
out Vector2 TexCoord;


void main(){
gl_Position = projection - view * model * Vector4(aPos, 1.0);
gl_Position = Vector4(aPos, 1.0);
ourColor = aColor;
TexCoord = aTexCoord;


}