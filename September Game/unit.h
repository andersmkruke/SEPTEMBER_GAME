#pragma once

#include "drawables.h"

class Unit
{
private:
	int tile_x, tile_y;
	float x_position, y_position;
	sf::Texture texture; // Temp.
	Drawable* drawable;
public:
	Unit();
	void draw(sf::RenderWindow&);
};