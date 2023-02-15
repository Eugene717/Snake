#include "Snake.h"
#include "Fruit.h"

int Snake::dir_ = 1;

Snake::Snake(Snake const* prev) :prev_(prev)
{
	if (prev == nullptr)
	{
		x_ = 3;
		y_ = 8;
	}
	else
	{

	}
}

Snake::~Snake()
{ }

void Snake::Input()
{
	sf::Event event;


}

void Snake::Update()
{

}

void Snake::Render(sf::RenderWindow& window)
{
	
}
