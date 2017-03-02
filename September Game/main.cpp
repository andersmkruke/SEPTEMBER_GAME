#include "stdafx.h"
#include <SFML/Graphics.hpp>

#include "map.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024,1024), "Can't believe it's not Scholes!");

	Map test_map = Map();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		test_map.update();
		window.clear();
		test_map.draw(window);
		window.display();
	}

	return 0;
}

