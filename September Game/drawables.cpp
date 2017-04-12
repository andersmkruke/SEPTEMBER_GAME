#include "stdafx.h"
#include "drawables.h"
#include <iostream>

bool Drawable::init(sf::Texture* ptr_texture, sf::Vector2f position)
{
	sprite.setTexture(*ptr_texture);
	sprite.setPosition(position);
	return true;
}

Drawable::Drawable()
{
	// TODO Set a standard texture
	sf::Texture t = sf::Texture();
	t.loadFromFile("Resources/Sprites/Tiles/grass.png");
	init(&t, sf::Vector2f(0.0f, 0.0f));
}

Drawable::Drawable(sf::Texture* ptr_texture)
{
	init(ptr_texture, sf::Vector2f(0.0f, 0.0f));
}

Drawable::Drawable(sf::Texture* ptr_texture, sf::Vector2f position)
{
	init(ptr_texture, position);
}

bool Drawable::setTexture(sf::Texture* ptr_texture)
{
	sprite.setTexture(*ptr_texture);
	return true;
}

sf::Vector2f Drawable::getPosition()
{
	return sprite.getPosition();
}

void Drawable::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

sf::Sprite Drawable::getSprite()
{
	return sprite;
}

float Drawable::getHeight()
{
	return sprite.getGlobalBounds().height;
}

void Drawable::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
