#include "game.hpp"

Game::Game() : mBall(ball(0.0f)) {
	mGameBlocks.push_back(Block(0.5f));
}

	//SE LLAMA UNA SOLA VEZ
void Game::Game_init() {
	mrBall.mTextureBall = mGameTextures.load_texture("Game/assets/ball.png", true);
	mrBall.init_vertex(ball::get_vertices(), ball::get_indices());
	
	mGameRender.mTextureBlock = mGameTextures.load_texture("Game/assets/block.png", false);
	mGameRender.init_vertex(Block::get_vertices(), Block::get_indices());
}

	//SE LLAMA 60 veces por segundo
void Game::render () {
	mrBall.on_render(ball::get_indices(), mBall.mModelMatrix.get_pointer_table(),1);
	mGameRender.on_render(Block::get_indices(), mGameBlocks[0].mModelMatrix.get_pointer_table(),2);
}