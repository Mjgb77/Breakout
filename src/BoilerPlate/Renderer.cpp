#include "Renderer.hpp"

Renderer::Renderer() {
	ProgramID = ShaderUtilities::LoadShaders("vertex.glsl", "frag.glsl");

}

Renderer::~Renderer() {
	glDeleteBuffers(1, &VertexBufferObject);
	glDeleteBuffers(1, &VertexArrayObject);
	glDeleteProgram(ProgramID);
}

void Renderer::Init(float vertexes[]) {
	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);

	glBindVertexArray(VertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);


	//ATTRIBUTES ARE 3: POSITION , COLOR, COORDINATES
	//change numbers to const, ex : 0 = firstAttribSlot
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		6 * sizeof(float),  // stride
		(void*)0            // array buffer offset
	);
	glVertexAttribPointer(1, 2, GL_FLAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(2, 2, GL_FLAT, GL_FALSE, 6 * sizeof(float), (void*)0);


	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::onRender() {
	glUseProgram(ProgramID);
	glBindVertexArray(VertexArrayObject);

}