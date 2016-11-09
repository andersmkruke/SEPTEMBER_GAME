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
	std::vector<Drawable*> on_top;

	void init(sf::Texture*, sf::Vector2f, char);

public:
	MapTile();
	MapTile(sf::Texture*);
	MapTile(sf::Texture*, sf::Vector2f);
	MapTile(sf::Texture*, sf::Vector2f, char);

	sf::Vector2f getPosition();
	sf::Vector2f getTopPosition();
	void pushOnTop(Drawable*);
	bool removeOnTop(Drawable*);
	void draw(sf::RenderWindow&);
};