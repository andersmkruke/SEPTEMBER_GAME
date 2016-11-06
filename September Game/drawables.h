#pragma once

#include <SFML/Graphics.hpp>

class Drawable
{
private:
	bool init(sf::Texture*, sf::Vector2f);
	sf::Texture* texture;
	sf::Sprite sprite;
public:
	Drawable();
	Drawable(sf::Texture*);
	Drawable(sf::Texture*, sf::Vector2f);

	bool setTexture(sf::Texture*);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	sf::Sprite getSprite();
	void draw(sf::RenderWindow&);
};

class AnimatedDrawable : public Drawable
{
private:

public:
	
};