#pragma once

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include "../../Engine/core/Renderer.hpp"
#include "ball.hpp"
#include "background.hpp"
#include "block.hpp"
#include "paddle.hpp"
#include "../../game_level.hpp"

#include "../../Engine/core/game_object.hpp"
#include "../../Engine/utilities/texture_manager.hpp"
#include "../../Engine/components/collision_component.hpp"



class Game;
class scene : public Engine::core::game_object
{
public:
	scene(int, int, Game *);

	void init(TextureManager *);

	void check_collision_with_paddle();
	void check_collisions_with_blocks();
	void update(double );
	int mWidth, mHeight;


	~scene();

	std::vector <block *> mGameBlocks;

	ball * mBall;
	paddle * mPaddle;
	collision_component mCollision;
	game_level mLevel;

	Game * mGame;

	int mIdLevel;

	bool mIsSticked;
};

#endif // !SCENE_HPP_
