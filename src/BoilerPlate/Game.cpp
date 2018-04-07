#include "game.hpp"

Game::Game() : mGameBlocks(Block(0.0f)) {
	
}

void Game::Game_init() {
	mGameTextures.load_texture("Game/assets/block.png");
	mGameRender.init_vertex(mGameBlocks.getVertices, mGameBlocks.mIndices);
}