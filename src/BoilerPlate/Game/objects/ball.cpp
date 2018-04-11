#include "ball.hpp"

#include "../../Engine/utilities/palette.hpp"
#include "../../Engine/math/Vector2.hpp"
#include "../../Engine/math/Vector3.hpp"

const float RADIUS = 0.02f;
#include <iostream>
using namespace std;

ball::ball(Engine::Math::Vector2 pPosition, paddle * pPaddle) 
{
	m_renderer = new renderer();
	mModelMatrix.translate(pPosition);
	mModelMatrix.scale(Engine::Math::Vector2(RADIUS));
	mPaddle = pPaddle;
	mVelocity = new velocity(Engine::Math::Vector2(0.0f, 0.0f));
}

void ball::init(TextureManager * textureManager)
{
	float * vertices = new float[36];
	init_quad_vertices(vertices, Palette::WHITE);
	mTextureId = textureManager->load_texture(TEXTURE_PATH, true);
	m_renderer->init(vertices, get_indices());
}

model_matrix ball::get_model_matrix()
{
	return mModelMatrix;
}

void ball::update(double deltaTime) {
	Engine::Math::Vector2 movement = mVelocity->get_velocity()*static_cast<float>(deltaTime);
	mModelMatrix.translate(movement);

	float xPos = mModelMatrix.transformPoint(0.0f).x;
	float yPos = mModelMatrix.transformPoint(0.0f).y;

	if (xPos < -1.0f || xPos > 1.0f) mVelocity->reverse_x_direction();
	if (yPos > 1.0f) mVelocity->reverse_y_direction();
	
}

void ball::render() 
{
	m_renderer->render(get_indices(), mModelMatrix.get_pointer_table(), mTextureId, 600.0f / 800.0f);
}

int * ball::get_indices()
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
