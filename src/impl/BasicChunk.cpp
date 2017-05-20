#include "BasicChunk.h"

unsigned short BasicChunk::getChunkWidth() {
	return 16;
}

unsigned short BasicChunk::getChunkHeight() {
	return 16;
}

unsigned short BasicChunk::getTileAt(unsigned short x, unsigned short y) {
	if(x >= 16 || y >= 16) return 0;
	return tiles[x][y];
}

BasicChunk::BasicChunk(const std::array<std::array<unsigned short, 16>, 16>& tiles) : tiles(tiles) {}
