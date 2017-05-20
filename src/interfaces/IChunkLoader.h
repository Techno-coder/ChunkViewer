#pragma once

#include <string>
#include "IChunk.h"

struct IChunkLoader {
	virtual std::unique_ptr<IChunk> getChunk(int x, int y) = 0;
	virtual ~IChunkLoader() {}
};
