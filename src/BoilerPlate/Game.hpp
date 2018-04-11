#pragma once
#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>
#include "Engine/core/Renderer.hpp"

#include "Game/objects/background.hpp"
#include "Game/objects/scene.hpp"

#include "Engine/utilities/texture_manager.hpp"

class Game {

	TextureManager * mGameTextures;

public:
	background * mBackground;
	scene * mScene;

	//FUNCTIONS &  CTORS
	Game(int width, int height);

	void Game_init();


	void render();
	void update();

	void update_size(int, int);

	int mWidth, mHeight;
};


#endif // !GAME_HPP_

