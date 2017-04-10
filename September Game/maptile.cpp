#include "stdafx.h"
#include "maptile.h"
#include "drawables.h"
#include <iostream>

#include <SFML\Graphics.hpp>

void MapTile::init(sf::Texture* ptr_texture, sf::Vector2f position, char height)
{
	this->position = position;
	this->height = height;

	for (int i = 0; i < height + 1; ++i)
	{
		Drawable *new_drawable = new Drawable(ptr_texture, sf::Vector2f(position.x, position.y - (32 * i)));
		addTile(new_drawable);
	}
}

MapTile::MapTile()
{
	sf::Texture t = sf::Texture();
	t.loadFromFile("Resources/Sprites/Tiles/grass.png");
	init(&t, sf::Vector2f(0.0f, 0.0f), 0);
}

MapTile::MapTile(sf::Texture* ptr_texture)
{
	init(ptr_texture, sf::Vector2f(0.0f, 0.0f), 0);
}

MapTile::MapTile(sf::Texture* ptr_texture, sf::Vector2f position)
{
	init(ptr_texture, position, 0);
}

MapTile::MapTile(sf::Texture* ptr_texture, sf::Vector2f position, char height)
{
	init(ptr_texture, position, height);
}

sf::Vector2f MapTile::getPosition()
{
	return position;
}

sf::Vector2f MapTile::getTopPosition()
{
	return sf::Vector2f(tiles.back()->getPosition());
}

void MapTile::addTile(Drawable *tile)
{
	tiles.push_back(tile);
}

void MapTile::popTile()
{
	tiles.pop_back();
	// TODO: Move units on top down to ground level
}



void MapTile::addUnit(Unit* add_unit)
{
	units.push_back(add_unit);
	add_unit->setPosition(getTopPosition()); // TODO: getTopPosition does not work when 'units' is not empty.
}

bool MapTile::removeUnit(Unit* remove_unit)
{
	for (auto it = units.begin(); it < units.end(); ++it)
	{
		if ((*it) == remove_unit)
		{
			units.erase(it);
			return true;
		}
	}
	return false;
}

void MapTile::draw(sf::RenderWindow &window)
{
	for (auto it = tiles.begin(); it < tiles.end(); ++it)
	{
		(*it)->draw(window);
	}
	for (auto it = units.begin(); it < units.end(); ++it)
	{
		(*it)->draw(window);
	}
}