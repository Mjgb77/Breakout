#pragma once
#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>
#include "Engine/core/Renderer.hpp"

#include "Game/objects/background.hpp"
#include "Game/objects/scene.hpp"

#include "Engine/utilities/texture_manager.hpp"
#include "Engine/utilities/input_manager.hpp"

#include "Engine/utilities/Sound.hpp"
#include "Engine/utilities/SoundPlayer.hpp"

class Game {

	TextureManager * mGameTextures;

public:
	background * mBackground;
	scene * mScene;


	Sound * mCollision;
	Sound * mInitSound;

	SoundPlayer * m_soundPlayer;

	//FUNCTIONS &  CTORS
	Game(int width, int height);

	void Game_init();


	void render();
	void update(double);

	void update_size(int, int);
	
	void play_collision_sound();

	int mWidth, mHeight;

private:
	void initialize_sounds();
};


#endif // !GAME_HPP_

