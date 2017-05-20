#pragma once

#include <SFML/Graphics/Texture.hpp>

struct ITileTextureResolver {
	virtual std::pair<sf::Texture&, sf::IntRect> getTexture(unsigned short tileID) = 0;
	virtual ~ITileTextureResolver() {}
};