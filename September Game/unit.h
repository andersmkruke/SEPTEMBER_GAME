#pragma once

#include "drawables.h"

class Unit
{
private:
	sf::Vector2i tile_coordinate;
	sf::Vector2f position;
	float x_offset = 64.0f;
	float y_offset = 0.0f;
	sf::Texture texture; // Temp.
	Drawable* drawable;

	void init(sf::Vector2i);
public:
	Unit();
	Unit::Unit(sf::Vector2i);

	sf::Vector2i getTileCoordinate();
	void setTileCoordinate(sf::Vector2i);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f new_position);
	float getHeight();

	void draw(sf::RenderWindow&);
};