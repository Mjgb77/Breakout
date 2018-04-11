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

enum block_type {SOLID, COLORFUL};

class block : public Engine::core::game_object {

	const char * TEXTURE_PATH_COLORFUL = "Game/assets/block.png";
	const char * TEXTURE_PATH_SOLID = "Game/assets/block_solid.png";

public:
	block(Engine::Math::Vector2, float, float, block_type, Color pColor = Palette::WHITE);

	void init(TextureManager *);
	model_matrix get_model_matrix();
	void render();

	block_type mType;

private:
	static int * get_indices();
	int mTextureId;
	Color mColor;

	model_matrix mModelMatrix;
};

#endif // !BLOCK_HPP_

