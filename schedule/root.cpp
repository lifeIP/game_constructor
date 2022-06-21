#include "lib.h"


int main() {
	MapWork asod;

	short screen_resolution_num = 0;// setting the screen resolution. 0 - nice  bad > 0

	sf::Uint32 style = sf::Style::Fullscreen;// setting the window style
	std::vector <sf::VideoMode> fullscreen_mode = sf::VideoMode::getFullscreenModes();


	//these variables show the screen size in pixels.
	int width = fullscreen_mode[screen_resolution_num].width;
	int height = fullscreen_mode[screen_resolution_num].height;

	sf::RenderWindow window(fullscreen_mode[screen_resolution_num], "GunGame", style);

	WorldMap map;
	int sizex = width / 32;
	int sizey = height / 32;
	std::cout << sizex << std::endl;
	std::cout << sizey << std::endl;
	int count = sizex * sizey;
	int* level = new int[count];
	for (int i = 0; i < count; i++) {
		level[i] = 890;
	}
	unsigned int tileID = 890;
	std::cout << asod.writing_the_basics("map_file.txt", 120, 120, tileID)  << std::endl;

	std::cout << map.loadMap("tile.png", sf::Vector2u(32, 32), level, sizex, sizey) << std::endl;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			//event processing
			if (event.type == sf::Event::EventType::KeyPressed) {
				switch (event.key.code)
				{

				case sf::Keyboard::Escape:
					window.close();
					break;

				default:
					break;
				}
			}
			//In this cycle, everything that depends on the buttons is processed.
		}
		//In this cycle, everything that is displayed on the screen is processed.
		window.clear(sf::Color::Black);
		window.draw(map);
		window.display();
	}
	return 0;
}