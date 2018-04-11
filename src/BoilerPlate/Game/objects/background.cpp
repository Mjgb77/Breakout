#include "background.hpp"

#include "../../Engine/utilities/palette.hpp"
#include "../../Engine/math/Vector2.hpp"
#include "../../Engine/math/Vector3.hpp"

#include <iostream>
using namespace std;

background::background(Engine::Math::Vector3 pPosition)
{
	m_renderer = new renderer();
	mModelMatrix.translate(pPosition);
}

void background::init(TextureManager * textureManager)
{
	float * vertices = new float[36];
	init_quad_vertices(vertices, Palette::WHITE);
	mTextureId = textureManager->load_texture(TEXTURE_PATH, false);
	m_renderer->init(vertices, get_indices());
}

void background::render()
{
	m_renderer->render(get_indices(), mModelMatrix.get_pointer_table(), mTextureId, 600.0f / 800.0f);
}

int * background::get_indices()
{
	static int indices[6];
	static bool loaded = false;
	if (!loaded) {

		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 3;
		indices[3] = 1;
		indices[4] = 2;
		indices[5] = 3;

		loaded = true;
	}

	return indices;
}
