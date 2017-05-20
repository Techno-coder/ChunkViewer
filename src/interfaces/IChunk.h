#pragma once

struct IChunk {
	virtual unsigned short getChunkWidth() = 0;
	virtual unsigned short getChunkHeight() = 0;
	virtual unsigned short getTileAt(unsigned short x, unsigned short y) = 0;
	virtual ~IChunk() {}
};
