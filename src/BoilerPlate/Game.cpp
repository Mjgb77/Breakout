#include "game.hpp"

Game::Game() {

}

void Game::Game_init() {
	mGameRender.init_vertex(mGameBlocks.mVertexes, mGameBlocks.indexes);
	mGameTextures.load_texture("Game/assets/block.png");
}