#include "game.hpp"
#include "game_level.hpp"

Game::Game(int pWidth, int pHeight)
{
	game_level bla;
	mGameBlocks = bla.get_blocks("1.txt", pWidth, pHeight);
	mBall = new ball(0.0f);
	mBackground = new background({ 0.0f,0.0f,-1.0f });
	mPaddle = new paddle({ 0.0f,-0.9f }, 0.1f, 0.05f);
}

void Game::Game_init()
{
	(*mBall).init(mGameTextures);
	(*mBackground).init(mGameTextures);
	(*mPaddle).init(mGameTextures);

	for (block *mb : mGameBlocks) 
	{
		(*mb).init(mGameTextures);
	}
}


void Game::update_size(int pWidth, int pHeight)
{
	mWidth = pWidth;
	mHeight = pHeight;
}

void Game::render ()
{
	(*mBackground).render();
	(*mScene).render();
}

void Game::update() {

}