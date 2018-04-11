#include "scene.hpp"

#include "../../game_level.hpp"

scene::scene(int pWidth, int pHeight)
{
	game_level bla;
	mGameBlocks = bla.get_blocks("1.txt", pWidth, pHeight);
	mBall = new ball(0.0f);
	mPaddle = new paddle({ 0.0f,-0.9f }, 0.1f, 0.05f);

	
}

void scene::render()
{

}


scene::~scene()
{

}
