#include "Fruit.h"

Fruit::Fruit()
{
	x_ = y_ = 0;
	body_.setSize(sf::Vector2f(34, 34));
	body_.setOutlineThickness(1);
	body_.setOutlineColor(sf::Color::Black);
	body_.setFillColor(sf::Color::Red);
	body_.setOrigin(35.f / 2, 35.f / 2);
}

void Fruit::Init(const int x, const int y)
{
	x_ = x;
	y_ = y;
	body_.setPosition(68.5 + 35.f * x_, 58.5 + 35.f * y_);
}

void Fruit::Render(sf::RenderWindow& window)
{
	window.draw(body_);
}
