#include "game.hpp"

Game::Game() {
	
}

void Game::Game_init() {
	std::cout << mGameTextures.load_texture("Game/assets/block.png", false) << std::endl;
	mGameRender.init_vertex(Block::get_vertices(), Block::get_indices());
}

void Game::render () {
	mGameRender.on_render(Block::get_indices());
}