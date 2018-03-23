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
	ProgramID = ShaderUtilities::load_shaders("Engine/shaders/vertex.glsl","Engine/shaders/frag.glsl");

	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);
	glGenBuffers(1, &indexBufferID);

	glBindVertexArray(VertexArrayObject);
	glBindVertexArray(indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mTemporalVertexes), mTemporalVertexes, GL_STATIC_DRAW);


	//ATTRIBUTES ARE 3: POSITION , COLOR, COORDINATES
	glVertexAttribPointer(
		FIRST_ATTRIBUTE_SLOT,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		STRIDE * sizeof(float),  // stride
		(void*)0            // array buffer offset
	);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glUseProgram(ProgramID);

	glUniform1i(glGetUniformLocation(ProgramID, "texture1"), 0);

	/*float resolution[] = { static_cast<float>(2), static_cast<float>(2) };
	glUniform2fv(glGetUniformLocation(ProgramID, "resolution"), 1, resolution);
	*/
}

void Renderer::on_render() {
	if (!wireFrame)glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (wireFrame) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	


	glBindVertexArray(VertexArrayObject);
	//glDrawArrays(VertexArrayObject, 0, 6);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glDrawElements(GL_TRIANGLES, sizeof(indexes), GL_UNSIGNED_INT, (void*)0);
}