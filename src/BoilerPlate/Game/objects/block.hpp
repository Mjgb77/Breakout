# pragma once
#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "../../Engine/core/game_object.hpp"
#include "../../Engine/core/vertex_object.hpp"
#include "../../Engine/components/velocity.hpp"

#include "../../Engine/components/model_matrix.hpp"
#include "../../Engine/core/Renderer.hpp"
#include "../../Engine/utilities/texture_manager.hpp"
#include <vector>

class block : public Engine::core::game_object {

	const char * TEXTURE_PATH = "Game/assets/block.png";

public:
	block(Engine::Math::Vector2, float, float, Color);

	void init(TextureManager *);
	void render();

private:
	static int * get_indices();
	int mTextureId;
	Color mColor;

	model_matrix mModelMatrix;
};

#endif // !BLOCK_HPP_

