#pragma once
#include "drawables.h"
#include "unit.h"
/*
* Holds information about a tile on a map, including (possibly stacked) Tile sprites
*/
class MapTile
{
private:
	sf::Vector2f position;
	char height;
	short pixel_height;
	std::vector<Drawable*> tiles;
	std::vector<Unit*> units;

	void init(sf::Texture*, sf::Vector2f, char);

public:
	MapTile();
	MapTile(sf::Texture*);
	MapTile(sf::Texture*, sf::Vector2f);
	MapTile(sf::Texture*, sf::Vector2f, char);

	sf::Vector2f getPosition();
	sf::Vector2f getTopPosition();
	void addTile(Drawable* tile);
	void popTile();
	void addUnit(Unit*);
	bool removeUnit(Unit*);
	void draw(sf::RenderWindow&);
};