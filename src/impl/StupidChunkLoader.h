#pragma once

#include "../interfaces/IChunkLoader.h"

class StupidChunkLoader : public IChunkLoader {
public:
	std::unique_ptr<IChunk> getChunk(int x, int y) override;
};

