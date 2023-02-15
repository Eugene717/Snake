#include "Fruit.h"

Fruit::Fruit()
{
	x_ = y_ = 0;
}

void Fruit::Init(const int x, const int y)
{
	x_ = x;
	y_ = y;
}

void Fruit::Render(sf::RenderWindow& window)
{

}
