#pragma once

#include "drawables.h"

class Map;

class Unit
{
private:
	sf::Vector2i tile_coordinate;
	sf::Vector2f position;
	float x_offset = 64.0f;
	float y_offset = 0.0f;
	sf::Texture texture; // Temp.
	Drawable* drawable;

	void init(Map&, sf::Vector2i);
public:
	Unit(Map&);
	Unit::Unit(Map&, sf::Vector2i);

	void setTileCoordinate(Map&, sf::Vector2i);
	
	void moveRight(Map&);
	void moveLeft(Map&);
	void moveDown(Map&);
	void moveUp(Map&);

	void draw(sf::RenderWindow&);
};