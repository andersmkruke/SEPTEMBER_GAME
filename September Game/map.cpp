#include "stdafx.h"
#include <vector>
#include "map.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAP
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Map::init(sf::Vector2f origin)
{
	// Set origin (position of top-left tile)
	this->origin = origin;
	std::srand(std::time(NULL));

	// load textures
	for (auto p = texture_paths.cbegin(); p < texture_paths.cend(); ++p)
	{
		sf::Texture* t = new sf::Texture();
		t->loadFromFile(*p);
		textures.insert(std::map<std::string, sf::Texture*>::value_type(*p, t));
	}

	// Create a 'standard' map, which includes all terrain types
	std::vector< std::vector<int> > example_map = {
		{3, 3, 3, 3, 3, 3, 2, 2},
		{3, 3, 3, 2, 2, 3, 2, 2},
		{3, 3, 3, 2, 2, 2, 2, 1},
		{3, 2, 2, 2, 2, 2, 1, 1},
		{3, 1, 1, 2, 2, 2, 1, 1},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	int i = 0;
	for (auto r = example_map.cbegin(); r < example_map.cend(); ++r)
	{
		std::vector<MapTile> row;
		int j = 0;
		for (auto c = r->cbegin(); c < r->cend(); ++c)
		{
			std::string texturepath = "";

			switch (*c)
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

			row.push_back(MapTile(textures.find(texturepath)->second, sf::Vector2f(origin.x - (i * 32.0f) + (j * 32.0f), origin.y + (i * 16.0f) + (j * 16.0f)), *c));
			++j;
		}
		map.push_back(row);
		++i;
	}

	units.push_back(new Unit());
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

	for (auto it = units.begin(); it < units.end(); ++it)
	{
		(*it)->draw(window);
	}
}