#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

/*
This program is a template for an SFML project using CMake and Vcpkg. 
You can duplicate the folder containing this project to easily set up a new 
SFML program. 
Just delete the "out" folder in the new project , or else you might get CMake errors.
*/

void drawPixel(sf::RenderWindow& window, sf::Vector2i position, sf::Color color) {
	std::array<sf::Vertex, 1> pixel = {
		sf::Vertex(sf::Vector2f(position.x, position.y), color)
	};
	window.draw(pixel.data(), 1, sf::Points);
}

int main() {
	//(sf::VideoMode{1920, 1080}) determines the window size
	sf::RenderWindow window{ sf::VideoMode{1920, 1080}, "SFML Demo" };
	sf::Clock c;
	auto last = c.getElapsedTime();

	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		auto now = c.getElapsedTime();
		auto diff = now - last;
		last = now;
		std::cout << 1 / diff.asSeconds() << " FPS " << std::endl;

		/*
		* DRAWING GOES HERE.
		*/
		//(x < 1000 determines the length of the line)
		for (auto x = 0; x < 1000; x++) {
			auto y = static_cast<int32_t>(2.0 / 3.0 * x + 40);
			//(sf::Color::Red) determines the color)
			drawPixel(window, sf::Vector2i(x, y), sf::Color::Red);
		}


		window.display();
	}

	return 0;
}


