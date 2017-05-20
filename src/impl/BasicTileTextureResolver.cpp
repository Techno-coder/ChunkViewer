#include "BasicTileTextureResolver.h"

std::pair<sf::Texture&, sf::IntRect> BasicTileTextureResolver::getTexture(unsigned short tileID) {
	int y = tileID / 8;
	int x = tileID % 8;
	return {tileMap, sf::IntRect{x * 16, y * 16, 16, 16}};
}

BasicTileTextureResolver::BasicTileTextureResolver() {
	tileMap.loadFromFile("resources/basictiles.png");
}
