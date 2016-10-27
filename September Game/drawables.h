#pragma once

#include <SFML/Graphics.hpp>

class Drawable
{
private:
	bool init(std::string, sf::Vector2f);
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Drawable();
	Drawable(std::string);
	Drawable(std::string, sf::Vector2f);

	bool setTexture(std::string);
	void setPosition(sf::Vector2f);
	sf::Sprite getSprite();
	void draw(sf::RenderWindow&);
};

class AnimatedDrawable : public Drawable
{
private:

public:
	
};

class Tile : public Drawable
{
private:

public:

};

class Unit : public AnimatedDrawable
{
private:

public:
	
};