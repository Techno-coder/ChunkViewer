#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "impl/StupidChunkLoader.h"
#include "interfaces/ITileTextureResolver.h"
#include "impl/BasicTileTextureResolver.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 800;

const int NUM_CHUNKS_TO_SHOW_WIDTH = 6;
const int NUM_CHUNKS_TO_SHOW_HEIGHT = 4;

int main() {
	int currentChunkXLeft = 0;
	int currentChunkYTop = 0;

	IChunkLoader* chunkLoader = new StupidChunkLoader();
	ITileTextureResolver* textureResolver = new BasicTileTextureResolver();

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chunk Viewer");
	window.setVerticalSyncEnabled(true);

	sf::Font textFont;
	textFont.loadFromFile("resources/helvetica.ttf");
	sf::Text textPosition("0 0", textFont, 30);
	textPosition.setFillColor(sf::Color::Black);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					return 0;
				case sf::Event::KeyPressed:
					switch (event.key.code) {
						case sf::Keyboard::Left: --currentChunkXLeft; break;
						case sf::Keyboard::Right: ++currentChunkXLeft; break;
						case sf::Keyboard::Up: --currentChunkYTop; break;
						case sf::Keyboard::Down: ++currentChunkYTop; break;
						default: break;
					}
					textPosition.setString(std::to_string(currentChunkXLeft) + " " + std::to_string(currentChunkYTop));
					break;
				default: break;
			}
		}

		window.clear(sf::Color::Black);
		for (int i = 0; i < NUM_CHUNKS_TO_SHOW_WIDTH; ++i) {
			for (int j = 0; j < NUM_CHUNKS_TO_SHOW_HEIGHT; ++j) {

				auto chunk = std::move(chunkLoader->getChunk(i + currentChunkXLeft, j + currentChunkYTop));
				for (unsigned short x = 0; x < chunk->getChunkWidth(); ++x) {
					for (unsigned short y = 0; y < chunk->getChunkHeight(); ++y) {

						auto tileData = textureResolver->getTexture(chunk->getTileAt(x, y));
						sf::Sprite tile(tileData.first, tileData.second);
						int tileX = (i * chunk->getChunkWidth() * tileData.second.width) + (x * tileData.second.width);
						int tileY = (j * chunk->getChunkHeight() * tileData.second.height) + (y * tileData.second.height);
						tile.setPosition(tileX, tileY);
						window.draw(tile);

					}
				}

			}
		}
		window.draw(textPosition);
		window.display();
	}

	delete chunkLoader;
	delete textureResolver;

}