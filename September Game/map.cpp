#include "stdafx.h"
#include <vector>
#include <random>
#include <time.h>
#include <iostream>

#include "map.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAP
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Map::init(sf::Vector2f origin)
{
	// Set origin (position of top-left tile)
	this->origin = origin;
	std::srand(std::time(NULL));
	// Create a 'standard' map, which includes all terrain types
	for (int i = 0; i < 14; ++i)
	{
		std::vector<MapTile> row;
		for (int j = 0; j < 14; ++j)
		{
			int rheight = std::rand() % 4;
			std::string texturepath = "";

			switch (rheight)
			{
			case 0:
				texturepath = "Resources/Sprites/Tiles/water.png";
				break;
			case 1:
				texturepath = "Resources/Sprites/Tiles/grass.png";
				break;
			case 2:
				texturepath = "Resources/Sprites/Tiles/grass.png";
				break;
			case 3:
				texturepath = "Resources/Sprites/Tiles/rock.png";
				break;
			default:
				texturepath = "Resources/Sprites/Tiles/earth.png";
			}

			row.push_back(MapTile(texturepath, sf::Vector2f(origin.x - (i * 32.0f) + (j * 32.0f), origin.y + (i * 16.0f) + (j * 16.0f)), rheight));
		}
		map.push_back(row);
	}
}

Map::Map()
{
	init(sf::Vector2f(480.0f, 256.0f));
}

Map::Map(std::FILE map_file)
{
	// TODO: Read map info from file and put into 'map'
}

void Map::rotate_clockwise()
{

}

void Map::draw(sf::RenderWindow &window)
{
	for (auto it_y = map.begin(); it_y < map.end(); ++it_y)
	{
		for (auto it_x = it_y->begin(); it_x < it_y->end(); ++it_x)
		{
			it_x->draw(window);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAP TILE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MapTile::init(std::string texture_path, sf::Vector2f position, char height)
{
	this->position = position;
	this->height = height;

	for (int i = 0; i < height + 1; ++i)
	{
		tiles.push_back(new Drawable(texture_path, sf::Vector2f(position.x, position.y - (32*i))));
	}
}

MapTile::MapTile()
{
	init("Resources/Sprites/Tiles/grass.png", sf::Vector2f(0.0f, 0.0f), 0);
}

MapTile::MapTile(std::string texture_path)
{
	init(texture_path, sf::Vector2f(0.0f, 0.0f), 0);
}

MapTile::MapTile(std::string texture_path, sf::Vector2f position)
{
	init(texture_path, position, 0);
}

MapTile::MapTile(std::string texture_path, sf::Vector2f position, char height)
{
	init(texture_path, position, height);
}

void MapTile::draw(sf::RenderWindow &window)
{
	for (std::vector<Drawable*>::iterator it = tiles.begin(); it < tiles.end(); ++it)
	{
		(*it)->draw(window);
	}
}
