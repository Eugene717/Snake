#pragma once
#include <SFML/Graphics.hpp>

class Fruit
{
	int x_, y_;
	sf::RectangleShape body_;
public:
	Fruit();
	void Init(const int x, const int y);
	void Render(sf::RenderWindow& window);
};

