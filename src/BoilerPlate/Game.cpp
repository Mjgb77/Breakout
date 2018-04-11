#include "game.hpp"
#include "game_level.hpp"

Game::Game(int pWidth, int pHeight)
{
	mScene = new scene(pWidth,pHeight);
	mBackground = new background({ 0.0f,0.0f,-1.0f });
}

void Game::Game_init()
{
	(*mBackground).init(mGameTextures);
	(*mScene).init(mGameTextures);

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

void Game::update(double pDeltaTime) {
	(*mBackground).update(pDeltaTime);
	(*mScene).update(pDeltaTime);
}