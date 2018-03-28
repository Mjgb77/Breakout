#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>
#include "Renderer.hpp"
#include "Engine\core\ball.hpp"
#include "Engine\core\block.hpp"
#include "resource_manager.hpp"

	class Game {
		
		TextureManager mGameTextures;
		

	public:
		Renderer mGameRender;
		Engine::core::Ball mGameBall;
		Engine::core::Block mGameBlocks;
		//FUNCTIONS &  CTORS
		Game();
		void Game_init();
		


	};




#endif // !GAME_H_INCLUDED

