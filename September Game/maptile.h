#pragma once
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

	void init(sf::Texture*, sf::Vector2f, char);
public:
	MapTile();
	MapTile(sf::Texture*);
	MapTile(sf::Texture*, sf::Vector2f);
	MapTile(sf::Texture*, sf::Vector2f, char);

	void draw(sf::RenderWindow&);
};