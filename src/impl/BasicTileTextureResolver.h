#pragma once

#include "../interfaces/ITileTextureResolver.h"

class BasicTileTextureResolver : public ITileTextureResolver {
	sf::Texture tileMap;
public:
	BasicTileTextureResolver();

	std::pair<sf::Texture&, sf::IntRect> getTexture(unsigned short tileID) override;
};

