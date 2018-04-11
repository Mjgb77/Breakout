#pragma once

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include "../../Engine/core/Renderer.hpp"
#include "ball.hpp"
#include "background.hpp"
#include "block.hpp"
#include "paddle.hpp"
#include "../../Engine/core/game_object.hpp"
#include "../../Engine/utilities/texture_manager.hpp"

class scene : public Engine::core::game_object
{
	TextureManager * mGameTexture;
public:

	scene(int, int);
	~scene();

	std::vector <block *> mGameBlocks;
	ball * mBall;
	background * mBackground;
	paddle * mPaddle;
};

#endif // !SCENE_HPP_
