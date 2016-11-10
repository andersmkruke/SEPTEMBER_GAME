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

	//Keyboard variables
	bool old_right = false;
	bool old_left = false;
	bool old_down = false;
	bool old_up = false;

	void init(sf::Vector2f);

public:
	Map();
	Map(std::FILE map_file);
	//WIP:
	void rotate_clockwise();
	void rotate_counterclockwise();
	sf::Vector2f getPositionFromCoordinate(sf::Vector2i);
	MapTile* getMapTileFromCoordinate(sf::Vector2i);
	void raiseTile(int x, int y); //return bool?
	void lowerTile(int x, int y); //return bool?
	void update();
	void draw(sf::RenderWindow&);
};