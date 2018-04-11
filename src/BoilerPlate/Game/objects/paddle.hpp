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
	void init(TextureManager *);
	void render();
private:
	int mTextureId;
	renderer * m_renderer;
	model_matrix mModelMatrix;
	static int * get_indices();
	static float * get_vertices();
};

#endif // !PADDLE_HPP_

