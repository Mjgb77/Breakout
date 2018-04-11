#include "scene.hpp"

#include "../../Engine/utilities/input_manager.hpp"

#include <string>
#include "../../Game.hpp"

scene::scene(int pWidth, int pHeight, Game * pGame)
{
	mIdLevel = 1;
	std::string filePath = "Game/assets/levels/level";
	filePath += mIdLevel + '0';
	filePath += ".txt";
	mGameBlocks = mLevel.get_blocks(filePath.c_str(), pWidth, pHeight);
	mPaddle = new paddle({ 0.0f,-0.9f }, 0.1f, 0.05f);
	mBall = new ball({ 0.0f,-0.8f }, mPaddle);
	mGame = pGame;
	add_child(mBall);
	add_child(mPaddle);

	mIsSticked = true;
	for (block * b : mGameBlocks) add_child(b);

}

void scene::init(TextureManager * pGameTextures)
{
	(*mBall).init(pGameTextures);
	(*mPaddle).init(pGameTextures);

	for (block *mb : mGameBlocks) (*mb).init(pGameTextures);
}

void scene::check_collision_with_paddle()
{
	int collisionType = mCollision.check_collision(mBall->get_model_matrix(), mPaddle->get_model_matrix());
	if (collisionType) {
		mBall->mVelocity->reverse_y_direction();
		Engine::Math::Vector2 disFromCenter = mCollision.vector_from_center(mBall->get_model_matrix(), mPaddle->get_model_matrix());

		mBall->mVelocity->sum_velocity({ (disFromCenter*250.0f).x,0.0f });
	}

}

void scene::check_collisions_with_blocks()
{
	std::vector <block*> validBlocks;

	for (block * tBlock : mGameBlocks) {
		int collisionType = mCollision.check_collision(mBall->get_model_matrix(), tBlock->get_model_matrix());
		if (collisionType) {
			if (collisionType == 1) mBall->mVelocity->reverse_x_direction();
			else mBall->mVelocity->reverse_y_direction();

			if (tBlock->mType == COLORFUL) {
				remove_child(tBlock);
				continue;
			}
		}
		validBlocks.push_back(tBlock);
	}

	mGameBlocks = validBlocks;
}


void scene::update(double pDeltaTime)
{
	check_collisions_with_blocks();
	check_collision_with_paddle();

	if (Engine::Input::InputManager::Instance().is_key_pressed(80)) mPaddle->go_left();
	else if (Engine::Input::InputManager::Instance().is_key_released(80)) mPaddle->stop_left();
	
	if (Engine::Input::InputManager::Instance().is_key_pressed(79)) mPaddle->go_right();
	if (Engine::Input::InputManager::Instance().is_key_released(79)) mPaddle->stop_right();

	if (mIsSticked) {
		if (Engine::Input::InputManager::Instance().is_key_pressed(82)) mBall->mVelocity->sum_velocity(Engine::Math::Vector2(0.0f, 40.0f));
	}

	if (mBall->get_model_matrix().transformPoint(Engine::Math::Vector2(0.0f)).y < -1.0f) {
		
	}

	game_object::update(pDeltaTime);
}


scene::~scene()
{

}
