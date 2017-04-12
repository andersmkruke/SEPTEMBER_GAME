#include "stdafx.h"

#include "unit.h"
#include "map.h"

#include <iostream>

void Unit::init(sf::Vector2i tile_coordinate)
{
	if (!texture.loadFromFile("Resources/Sprites/Units/unit.png"))
		std::cout << "ERROR - FILE NOT FOUND! (Resources/Sprites/Units/example_unit.png)" << std::endl;

	this->tile_coordinate = tile_coordinate;
	this->position = sf::Vector2f(0.0f, 0.0f);

	drawable = new Drawable(&texture, this->position);
}

Unit::Unit()
{
	init(sf::Vector2i(0, 0)); // WARNING! Possible exception if position values are outside map bounds
}

Unit::Unit(sf::Vector2i coordinate)
{
	init(coordinate);
}

sf::Vector2i Unit::getTileCoordinate()
{
	return tile_coordinate;
}

void Unit::setTileCoordinate(sf::Vector2i coordinate)
{
	tile_coordinate = coordinate;
}

sf::Vector2f Unit::getPosition()
{
	return position;
}

void Unit::setPosition(sf::Vector2f new_position)
{
	this->position = new_position;
	drawable->setPosition(new_position);
}

float Unit::getHeight()
{
	return drawable->getHeight();
}


void Unit::draw(sf::RenderWindow& window)
{
	drawable->draw(window);
} 
