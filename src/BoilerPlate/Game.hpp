#pragma once
#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>
#include "Engine/core/Renderer.hpp"

#include "Game/objects/background.hpp"
#include "Game/objects/scene.hpp"

#include "Engine/utilities/texture_manager.hpp"
#include "Engine/utilities/input_manager.hpp"

class Game {

	TextureManager * mGameTextures;
	//Engine::Input::InputManager mInputManager;

public:
	background * mBackground;
	scene * mScene;

	//FUNCTIONS &  CTORS
	Game(int width, int height);

	void Game_init();


	void render();
	void update(double);

	void update_size(int, int);

	int mWidth, mHeight;
};


#endif // !GAME_HPP_

