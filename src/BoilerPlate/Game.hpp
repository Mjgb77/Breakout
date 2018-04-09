#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "Engine/core/Renderer.hpp"
#include "block.hpp"
#include "Engine/utilities/resource_manager.hpp"

class Game {

	TextureManager mGameTextures;

public:
	Renderer mGameRender;
	std::vector <Block> mGameBlocks;
	//FUNCTIONS &  CTORS
	Game();
	void Game_init();
	void render();
};


#endif // !GAME_H_INCLUDED

