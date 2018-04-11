# pragma once
#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include "../../Engine/core/game_object.hpp"
#include "../../Engine/core/vertex_object.hpp"
#include "../../Engine/components/velocity.hpp"

#include "../../Engine/components/model_matrix.hpp"
#include <vector>
#include "../../Engine/core/Renderer.hpp"
#include "../../Engine/utilities/texture_manager.hpp"

class paddle : public Engine::core::game_object {
	const char * TEXTURE_PATH = "Game/assets/paddle.png";
public:
	paddle(Engine::Math::Vector2, float, float);
	model_matrix get_model_matrix();
	void init(TextureManager *);

	void go_left();
	void go_right();

	void stop_right();
	void stop_left();

	void update(double);
	void render();


private:
	int mTextureId;
	renderer * m_renderer;
	model_matrix mModelMatrix;

	velocity * mVelocity;
	static int * get_indices();
};

#endif // !PADDLE_HPP_

