#pragma once
#include <SFML/Graphics.hpp>

class Fruit
{
	int x_, y_;
	static sf::Texture texture_;
	sf::Sprite sprite_;
public:
	Fruit();
	void Init(const int x, const int y);
	void Render(sf::RenderWindow& window);
};

