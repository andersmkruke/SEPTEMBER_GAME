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

void MapTile::draw(sf::RenderWindow &window)
{
	for (std::vector<Drawable*>::iterator it = tiles.begin(); it < tiles.end(); ++it)
	{
		(*it)->draw(window);
	}
}