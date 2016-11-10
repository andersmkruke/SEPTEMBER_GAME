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

void Unit::setTileCoordinate(Map& map, sf::Vector2i coordinate)
{
	// TDOO: Check for out of bounds
	map.getMapTileFromCoordinate(tile_coordinate)->removeOnTop(drawable);
	tile_coordinate = coordinate;
	map.getMapTileFromCoordinate(tile_coordinate)->pushOnTop(drawable);
}

void Unit::moveRight(Map& map)
{
	if (tile_coordinate.x < 7)
	{
		map.getMapTileFromCoordinate(tile_coordinate)->removeOnTop(drawable);
		tile_coordinate = sf::Vector2i(tile_coordinate.x+1, tile_coordinate.y);
		map.getMapTileFromCoordinate(tile_coordinate)->pushOnTop(drawable);
		drawable->setPosition(map.getPositionFromCoordinate(tile_coordinate));
	}
}

void Unit::moveLeft(Map& map)
{
	if (tile_coordinate.x > 0)
	{
		map.getMapTileFromCoordinate(tile_coordinate)->removeOnTop(drawable);
		tile_coordinate = sf::Vector2i(tile_coordinate.x - 1, tile_coordinate.y);
		map.getMapTileFromCoordinate(tile_coordinate)->pushOnTop(drawable);
		drawable->setPosition(map.getPositionFromCoordinate(tile_coordinate));
	}
}

void Unit::moveDown(Map& map)
{
	if (tile_coordinate.y < 7)
	{
		map.getMapTileFromCoordinate(tile_coordinate)->removeOnTop(drawable);
		tile_coordinate = sf::Vector2i(tile_coordinate.x, tile_coordinate.y+1);
		map.getMapTileFromCoordinate(tile_coordinate)->pushOnTop(drawable);
		drawable->setPosition(map.getPositionFromCoordinate(tile_coordinate));
	}
}

void Unit::moveUp(Map& map)
{
	if (tile_coordinate.y > 0)
	{
		map.getMapTileFromCoordinate(tile_coordinate)->removeOnTop(drawable);
		tile_coordinate = sf::Vector2i(tile_coordinate.x, tile_coordinate.y-1);
		map.getMapTileFromCoordinate(tile_coordinate)->pushOnTop(drawable);
		drawable->setPosition(map.getPositionFromCoordinate(tile_coordinate));
	}
}


void Unit::draw(sf::RenderWindow& window)
{
	drawable->draw(window);
} 
