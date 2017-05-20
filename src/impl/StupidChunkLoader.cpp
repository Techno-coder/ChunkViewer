#include <array>
#include <cstdlib>
#include "StupidChunkLoader.h"
#include "BasicChunk.h"

std::unique_ptr<IChunk> StupidChunkLoader::getChunk(int x, int y) {
	std::array<std::array<unsigned short, 16>, 16> tiles;
	unsigned int bijectiveResult = (unsigned int) (x >= y ? x * x + x + y : x + y * y);
	srand(bijectiveResult);
	for(int i = 0; i < 16; ++i) {
		for(int j = 0; j < 16; ++j) {
			tiles[i][j] = (unsigned short) (rand() % 8);
		}
	}
	return std::make_unique<BasicChunk>(tiles);
}
