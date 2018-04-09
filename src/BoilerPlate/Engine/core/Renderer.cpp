#include "Renderer.hpp"
#include "../math/matrix_4.hpp"

#include <vector>

const int FIRST_ATTRIBUTE_SLOT = 0;
const int SECOND_ATTRIBUTE_SLOT = 1;
const int THIRD_ATTRIBUTE_SLOT = 2;
const int STRIDE = 6;


Renderer::Renderer() {
}

Renderer::~Renderer() {
	//glDeleteBuffers(1, &VertexBufferObject);
	//glDeleteBuffers(1, &ElementBufferObject);
	//glDeleteVertexArrays(1, &VertexArrayObject);

}



void Renderer::init_vertex(float vertices[], int indices[]) {

	ProgramID = ShaderUtilities::load_shaders("Engine/shaders/vertex.glsl", "Engine/shaders/frag.glsl");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);
	glGenBuffers(1, &ElementBufferObject);


	glBindVertexArray(VertexArrayObject);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(int), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(float), vertices, GL_STATIC_DRAW);
	//


	////ATTRIBUTES ARE 3: POSITION , COLOR, COORDINATES
	//glVertexAttribPointer(
	//	FIRST_ATTRIBUTE_SLOT,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	//	3,                  // size
	//	GL_FLOAT,           // type
	//	GL_FALSE,           // normalized?
	//	STRIDE * sizeof(float),  // stride
	//	(void*)0            // array buffer offset
	//);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glUseProgram(ProgramID);
	glUniform1i(glGetUniformLocation(ProgramID, "texture1"), 0);
}

using namespace std;
void Renderer::on_render(int indices[], float pModelMatrix [], int pIdTexture)  {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glUseProgram(ProgramID);

	Engine::Math::matrix_4 view = Engine::Math::matrix_4();
	Engine::Math::matrix_4 projection = Engine::Math::matrix_4();

	view.translate({ 0.0f,0.0f,-7.0f });
	//view.rotate_z(0.0f);
	projection.make_perspective(120.0f, 0.1f, 30.0f);

	//retrieve the matrix uniform locations
	GLuint modelLoc = glGetUniformLocation(ProgramID, "model");
	GLuint viewLoc = glGetUniformLocation(ProgramID, "view");
	GLuint projectionLoc = glGetUniformLocation(ProgramID, "projection");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, pModelMatrix);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.get_pointer());
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection.get_pointer());


	glBindVertexArray(VertexArrayObject);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pIdTexture);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
	glDrawElements(GL_TRIANGLES, 6 * sizeof(int), GL_UNSIGNED_INT, (void*)0);
}