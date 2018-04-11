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
#include "paddle.hpp"

class ball : public Engine::core::game_object {
	const char * TEXTURE_PATH = "Game/assets/ball.png";
public:
	ball(Engine::Math::Vector2, paddle *);
	void init(TextureManager *);
	model_matrix get_model_matrix();
	void update(double);
	void render();

	velocity * mVelocity;

private:
	int mTextureId;
	renderer * m_renderer;
	model_matrix mModelMatrix;

	paddle * mPaddle;

	static int * get_indices();
};

#endif // !BALL_HPP_INCLUDED

