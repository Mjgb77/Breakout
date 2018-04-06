#include "game.hpp"

Game::Game() {
	
}

void Game::Game_init() {
	mGameTextures.load_texture("Game/assets/block.png");
	//mGameRender.init_vertex(mGameBlocks.mVertexes, mGameBlocks.indexes);
}