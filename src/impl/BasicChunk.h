#pragma once

#include <array>
#include "../interfaces/IChunk.h"

class BasicChunk : public IChunk {
	std::array<std::array<unsigned short, 16>, 16> tiles;
public:
	BasicChunk(const std::array<std::array<unsigned short, 16>, 16>& tiles);

	unsigned short getChunkWidth() override;
	unsigned short getChunkHeight() override;
	unsigned short getTileAt(unsigned short x, unsigned short y) override;
};

