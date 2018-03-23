#include "Renderer.hpp"


const int FIRST_ATTRIBUTE_SLOT = 0;
const int SECOND_ATTRIBUTE_SLOT = 1;
const int THIRD_ATTRIBUTE_SLOT = 2;
const int STRIDE=6;


Renderer::Renderer() {
	wireFrame = false;
}

Renderer::~Renderer() {
	//glDeleteBuffers(1, &VertexBufferObject);
	//glDeleteBuffers(1, &ElementBufferObject);
	//glDeleteVertexArrays(1, &VertexArrayObject);

}

void Renderer::switch_view() {
	if (wireFrame) wireFrame = false;
	else {
		wireFrame = true;
	}
}



void Renderer::init_vertex() {
	ProgramID = ShaderUtilities::load_shaders("vertex.glsl", "frag.glsl");

	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);

	glBindVertexArray(VertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);


	//ATTRIBUTES ARE 3: POSITION , COLOR, COORDINATES
	glVertexAttribPointer(
		FIRST_ATTRIBUTE_SLOT,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		STRIDE * sizeof(float),  // stride
		(void*)0            // array buffer offset
	);
	glVertexAttribPointer(SECOND_ATTRIBUTE_SLOT, 2, GL_FLAT, GL_FALSE, STRIDE * sizeof(float), (void*)0);
	glVertexAttribPointer(THIRD_ATTRIBUTE_SLOT, 2, GL_FLAT, GL_FALSE, STRIDE * sizeof(float), (void*)0);




	glEnableVertexAttribArray(FIRST_ATTRIBUTE_SLOT);
	glEnableVertexAttribArray(SECOND_ATTRIBUTE_SLOT);
	glEnableVertexAttribArray(THIRD_ATTRIBUTE_SLOT);



	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	
}

void Renderer::on_render() {
	if (!wireFrame)glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (wireFrame) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glUseProgram(ProgramID);
	glBindVertexArray(VertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}