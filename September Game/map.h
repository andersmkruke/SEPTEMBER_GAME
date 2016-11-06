#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "maptile.h"
#include "unit.h"

class Map
{
private:
	std::vector<std::vector<MapTile>> map;
	sf::Vector2f origin;
	std::vector<std::string> texture_paths = {
		"Resources/Sprites/Tiles/water.png",
		"Resources/Sprites/Tiles/grass.png",
		"Resources/Sprites/Tiles/rock.png",
		"Resources/Sprites/Tiles/earth.png"
	};
	std::map<std::string, sf::Texture*> textures;
	std::vector<Unit*> units;

	void init(sf::Vector2f);

public:
	Map();
	Map(std::FILE map_file);
	//WIP:
	void rotate_clockwise();
	void rotate_counterclockwise();
	void raiseTile(int x, int y); //return bool?
	void lowerTile(int x, int y); //return bool?
	void draw(sf::RenderWindow&);
};