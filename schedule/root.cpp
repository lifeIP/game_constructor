#include "lib.h"


int main() {
	short screen_resolution_num = 0;// setting the screen resolution. 0 - nice  bad > 0

	sf::Uint32 style = sf::Style::Fullscreen;// setting the window style
	std::vector <sf::VideoMode> fullscreen_mode = sf::VideoMode::getFullscreenModes();


	//these variables show the screen size in pixels.
	int width = fullscreen_mode[screen_resolution_num].width;
	int height = fullscreen_mode[screen_resolution_num].height;

	sf::RenderWindow window(fullscreen_mode[screen_resolution_num], "GunGame", style);

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
	
	WorldMap map;
	const std::string map_storage = "1";
	const std::string map_changes = "2";
	const std::string map_buffer = "3";
	sf::Vector2u size_map = sf::Vector2u(sizex,sizey);
	sf::Vector2u coord_center = sf::Vector2u((unsigned int)(sizex/2), (unsigned int)(sizey/2));
	MeshForMowing mesh(map_storage,map_changes, map_buffer,size_map,coord_center);
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
		window.clear();
		window.draw(map);
		mesh.printFrame(&window);
		window.display();
	}
	return 0;
}