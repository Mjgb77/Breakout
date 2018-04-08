#include "game.hpp"

Game::Game() : mGameBlocks(Block(0.0f)) {
	
}

void Game::Game_init() {
	mGameTextures.load_texture("Game/assets/ball.png",true);
	mGameTextures.load_texture("Game/assets/block.png", false);
	mGameRender.init_vertex(mGameBlocks.getVertices, mGameBlocks.mIndices);
}

void Game::render () {
	mGameRender.on_render(mGameBlocks.mIndices);
}