#include "game.hpp"
#include "game_level.hpp"

Game::Game(int pWidth, int pHeight)
{
	mScene = new scene(pWidth,pHeight, this);
	mBackground = new background({ 0.0f,0.0f,-1.0f });

	initialize_sounds();
}

void Game::Game_init()
{
	(*mBackground).init(mGameTextures);
	(*mScene).init(mGameTextures);

	m_soundPlayer->PlaySound(mInitSound);
}


void Game::update_size(int pWidth, int pHeight)
{
	mWidth = pWidth;
	mHeight = pHeight;
}

void Game::play_collision_sound()
{
	m_soundPlayer->PlaySound(mCollision);
}

void Game::initialize_sounds()
{
	mCollision = new Sound("Game/assets/sounds/collision.wav");
	mInitSound = new Sound("Game/assets/sounds/init.wav");

	m_soundPlayer = new SoundPlayer();

	m_soundPlayer->AddSound(mCollision);
	m_soundPlayer->AddSound(mInitSound);
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