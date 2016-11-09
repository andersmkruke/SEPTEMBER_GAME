#include "stdafx.h"

#include "unit.h"
#include "map.h"

#include <iostream>

void Unit::init(Map& map, sf::Vector2i tile_coordinate)
{
	if (!texture.loadFromFile("Resources/Sprites/Units/unit.png"))
		std::cout << "ERROR - FILE NOT FOUND! (Resources/Sprites/Units/example_unit.png)" << std::endl;

	this->tile_coordinate = tile_coordinate;
	sf::Vector2f tile_pos = map.getPositionFromCoordinate(tile_coordinate);
	this->position = sf::Vector2f(tile_pos.x, tile_pos.y);

	drawable = new Drawable(&texture, this->position);
	map.getMapTileFromCoordinate(tile_coordinate)->pushOnTop(drawable);
}

Unit::Unit(Map& map)
{
	init(map, sf::Vector2i(0, 0)); // WARNING! Possible exception if position values are outside map bounds
}

Unit::Unit(Map& map, sf::Vector2i coordinate)
{
	init(map, coordinate);
}

void Unit::draw(sf::RenderWindow& window)
{
	drawable->draw(window);
} 
