#include "game_level.hpp"
#include <istream>

game_level::game_level()
{
}


game_level::~game_level()
{
}

std::vector<block*> game_level::get_blocks(const char * pLevelPath, int pLevelWidth, int pLevelHeight)
{
	std::vector<block*> blocks;

	std::ifstream ifs(pLevelPath);

	int rows, columns;
	float heightRatio;

	ifs >> rows >> columns >> heightRatio;

	float blockWidth =  static_cast<float> (pLevelWidth) / columns;
	float blockHeight = static_cast<float> (pLevelHeight) / rows * heightRatio;

	// Initialize level tiles based on tileData

	float dy = 2.0f / rows * heightRatio;
	float dx = 2.0f / columns;

	float sy = 1.0f - dy / 2.0f;
	for (int i = 0; i < rows; i++, sy -= dy) {
		
		float sx = -1.0f + dx / 2.0f;
		for (int j = 0; j < columns; j++, sx += dx) {
			int blockType;
			ifs >> blockType;

			if (!blockType) continue;
			
			blockType--;
			
			if (!blockType) blocks.push_back(new block({ sx,sy }, dx / 2, dy / 2, block_type::SOLID));
			else blocks.push_back(new block({ sx,sy }, dx/2, dy/2, block_type::COLORFUL, BlockColors[blockType-1]));
		}


	}

	return blocks;
}
