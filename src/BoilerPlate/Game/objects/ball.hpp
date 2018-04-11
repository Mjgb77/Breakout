# pragma once
#ifndef BALL_HPP_INCLUDED
#define BALL_HPP_INCLUDED

#include "../../Engine/core/game_object.hpp"
#include "../../Engine/core/vertex_object.hpp"
#include "../../Engine/components/velocity.hpp"

#include "../../Engine/components/model_matrix.hpp"
#include <vector>
#include "../../Engine/core/Renderer.hpp"
#include "../../Engine/utilities/texture_manager.hpp"

class ball : public Engine::core::game_object {
	const char * TEXTURE_PATH = "Game/assets/ball.png";
public:
	ball(Engine::Math::Vector2);
	void init(TextureManager *);
	
	void update(double);
	void render();


private:
	int mTextureId;
	renderer * m_renderer;
	model_matrix mModelMatrix;

	velocity * mVelocity;

	static int * get_indices();
	static float * get_vertices();
};

#endif // !BALL_HPP_INCLUDED

