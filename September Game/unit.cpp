#include "stdafx.h"

#include "unit.h"
#include <iostream>

Unit::Unit()
{
	if (!texture.loadFromFile("Resources/Sprites/Units/example_unit.png"))
		std::cout << "ERROR - FILE NOT FOUND! (Resources/Sprites/Units/example_unit.png)" << std::endl;
	tile_x = 0;
	tile_y = 0;
	x_position = 496.0f;
	y_position = 256.0f;
	drawable = new Drawable(&texture, sf::Vector2f(x_position, y_position));
}

void Unit::draw(sf::RenderWindow& window)
{
	drawable->draw(window);
}
