#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "drawables.h"
/*
* Holds information about a tile on a map, including (possibly stacked) Tile sprites
*/
class MapTile
{
private:
	sf::Vector2f position;
	char height;
	std::vector<Drawable*> tiles;

	void init(std::string, sf::Vector2f, char);
public:
	MapTile();
	MapTile(std::string);
	MapTile(std::string, sf::Vector2f);
	MapTile(std::string, sf::Vector2f, char);

	void draw(sf::RenderWindow&);
};

class Map
{
private:
	std::vector<std::vector<MapTile>> map;
	sf::Vector2f origin;
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

