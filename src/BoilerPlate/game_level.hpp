#pragma once

#ifndef GAME_LEVEL_HPP_
#define GAME_LEVEL_HPP_


#include "Engine/core/game_object.hpp"
#include "Game/objects/block.hpp"
#include "Engine/utilities/palette.hpp"
#include <vector>

class game_level : Engine::core::game_object
{
	std::vector <Color> BlockColors = {Palette::PURPLE, Palette::CYAN, Palette::GREEN, Palette::FLAME, Palette::RED};
public:
	game_level();
	~game_level();

	std::vector <block *> get_blocks(const char *, int, int);

private:
	int mLifes;
};

#endif // !GAME_LEVEL_HPP_
