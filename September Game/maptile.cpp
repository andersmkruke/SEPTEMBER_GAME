#include "stdafx.h"
#include "maptile.h"
#include "drawables.h"

#include <SFML\Graphics.hpp>

void MapTile::init(sf::Texture* ptr_texture, sf::Vector2f position, char height)
{
	this->position = position;
	this->height = height;

	for (int i = 0; i < height + 1; ++i)
	{
		tiles.push_back(new Drawable(ptr_texture, sf::Vector2f(position.x, position.y - (32 * i))));
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

void MapTile::pushOnTop(Drawable* drawable)
{
	on_top.push_back(drawable);
}

bool MapTile::removeOnTop(Drawable* remove)
{
	for (auto it = on_top.begin(); it < on_top.end(); ++it)
	{
		if ((*it) == remove)
		{
			on_top.erase(it);
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
	for (auto it = on_top.begin(); it < on_top.end(); ++it)
	{
		(*it)->draw(window);
	}
}