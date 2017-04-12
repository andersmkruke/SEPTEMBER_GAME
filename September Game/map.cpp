#include "stdafx.h"
#include <vector>
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

	tile_height = map.size();
	tile_width = map[0].size();

	units.push_back(new Unit());
	active_unit = units.back();
	addUnitToTile(active_unit);
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
	// TODO: Rotate the map 90 degrees clockwise
}

sf::Vector2f Map::getPositionFromCoordinate(sf::Vector2i coordinate)
{
	return map[coordinate.y][coordinate.x].getTopPosition();
}

MapTile* Map::getMapTileFromCoordinate(sf::Vector2i coordinate)
{
	return &map[coordinate.y][coordinate.x];
}

void Map::addUnitToTile(Unit* unit)
{
	sf::Vector2i tile_coordinate = unit->getTileCoordinate();
	map[tile_coordinate.y][tile_coordinate.x].addUnit(unit);
}

void Map::moveUnit(Unit *unit, Direction direction)
{
	sf::Vector2i tile_coordinate = unit->getTileCoordinate();
	int new_x, new_y;
	switch (direction)
	{
	case Direction::up:
		new_x = tile_coordinate.x;
		new_y = (tile_coordinate.y - 1 < 0) ? 0 : (tile_coordinate.y - 1);
		break;
	case Direction::up_right:
		// TODO: Move only if up-right square is free (ATM: Moves even if just one of up/right is free)
		new_x = (tile_coordinate.x + 1 < tile_width) ? (tile_coordinate.x + 1) : (tile_width - 1);
		new_y = (tile_coordinate.y - 1 < 0) ? 0 : (tile_coordinate.y - 1);
		break;
	case Direction::right:
		new_x = (tile_coordinate.x + 1 >= tile_width) ? (tile_width - 1) : (tile_coordinate.x + 1);
		new_y = tile_coordinate.y;
		break;
	case Direction::down_right:
		// TODO: Move only if down-right square is free (ATM: Moves even if just one of down/right is free)
		new_x = (tile_coordinate.x + 1 >= tile_width) ? (tile_width - 1) : (tile_coordinate.x + 1);
		new_y = (tile_coordinate.y + 1 >= tile_height) ? (tile_height - 1) : (tile_coordinate.y + 1);
		break;
	case Direction::down:
		new_x = tile_coordinate.x;
		new_y = (tile_coordinate.y + 1 >= tile_height) ? (tile_height - 1) : (tile_coordinate.y + 1);
		break;
	case Direction::down_left:
		// TODO: Move only if down-left square is free (ATM: Moves even if just one of down/left is free)
		new_x = (tile_coordinate.x - 1 < 0) ? 0 : (tile_coordinate.x - 1);
		new_y = (tile_coordinate.y + 1 >= tile_height) ? (tile_height - 1) : (tile_coordinate.y + 1);
		break;
	case Direction::left:
		new_x = (tile_coordinate.x - 1 < 0) ? 0 : (tile_coordinate.x - 1);
		new_y = tile_coordinate.y;
		break;
	case Direction::up_left:
		// TODO: Move only if up-left square is free (ATM: Moves even if just one of up/left is free)
		new_x = (tile_coordinate.x - 1 < 0) ? 0 : (tile_coordinate.x - 1);
		new_y = (tile_coordinate.y - 1 < 0) ? 0 : (tile_coordinate.y - 1);
		break;
	default:
		new_x = tile_coordinate.x;
		new_y = tile_coordinate.y;
	}
	
	// TODO: Check to see if move is legal (call a valid_move function in unit). Some units may e.g. only ascend one block at a time.
	map[tile_coordinate.y][tile_coordinate.x].removeUnit(unit);
	unit->setTileCoordinate(sf::Vector2i(new_x, new_y));
	map[new_y][new_x].addUnit(unit);
}

void Map::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!old_right)
		{
			for (auto it = units.begin(); it < units.end(); ++it)
			{
				// CHANGE (*it)->moveRight(*this);
				moveUnit(active_unit, Direction::right);
			}
		}
		old_right = true;
	}
	else
	{
		old_right = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!old_left)
		{
			for (auto it = units.begin(); it < units.end(); ++it)
			{
				// CHANGE (*it)->moveLeft(*this);
				moveUnit(active_unit, Direction::left);
			}
		}
		old_left = true;
	}
	else
	{
		old_left = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!old_down)
		{
			for (auto it = units.begin(); it < units.end(); ++it)
			{
				// CHANGE (*it)->moveDown(*this);
				moveUnit(active_unit, Direction::down);
			}
		}
		old_down = true;
	}
	else
	{
		old_down = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!old_up)
		{
			for (auto it = units.begin(); it < units.end(); ++it)
			{
				// CHANGE (*it)->moveUp(*this);
				moveUnit(active_unit, Direction::up);
			}
		}
		old_up = true;
	}
	else
	{
		old_up = false;
	}
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
