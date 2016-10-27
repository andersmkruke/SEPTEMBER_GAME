#include "stdafx.h"
#include "drawables.h"
#include <iostream>

bool Drawable::init(std::string texture_path, sf::Vector2f position)
{
	if (!texture.loadFromFile(texture_path)) { throw std::exception("ERROR"); }
	sprite.setTexture(texture);
	sprite.setPosition(position);
	return true;
}

Drawable::Drawable()
{
	// TODO Set a standard texture
	init("Resources/Sprites/Tiles/grass.png", sf::Vector2f(0.0f, 0.0f));
}

Drawable::Drawable(std::string texture_path)
{
	init(texture_path, sf::Vector2f(0.0f, 0.0f));
}

Drawable::Drawable(std::string texture_path, sf::Vector2f position)
{
	init(texture_path, position);
}

bool Drawable::setTexture(std::string texture_path)
{
	if (!texture.loadFromFile(texture_path)) { return false; }
	sprite.setTexture(texture);
	return true;
}

void Drawable::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

sf::Sprite Drawable::getSprite()
{
	return sprite;
}

void Drawable::draw(sf::RenderWindow &window)
{
	window.draw(sprite);	
}
