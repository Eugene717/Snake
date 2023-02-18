#include "Snake.h"
#include "Fruit.h"

int Snake::dir_ = 1;
sf::RectangleShape Snake::body_;
std::list<Snake*> Snake::snake_;
bool Snake::eatFruit_ = false;

Snake::Snake(Snake const* prev) :prev_(prev)
{
	if (prev == nullptr)
	{
		body_.setSize(sf::Vector2f(34, 34));
		body_.setOutlineThickness(1);
		body_.setOutlineColor(sf::Color::Black);
		body_.setFillColor(sf::Color::Green);
		body_.setOrigin(35.f / 2.f, 35.f / 2.f);

		x_ = 4;
		y_ = 7;
		snake_.push_back(this);

		Snake* second = new Snake(x_ - 1, y_);
		Snake* third = new Snake(x_ - 2, y_);
	}
	else
	{
		prev_ = prev;
		x_ = prev_->x_;
		y_ = prev_->y_;
		snake_.push_back(this);
	}
}

Snake::Snake(int x, int y) : x_(x), y_(y)
{
	prev_ = snake_.back();
	snake_.push_back(this);
}

Snake::~Snake()
{ 
	for (auto it = snake_.begin(); it != snake_.end(); ++it)
	{
		delete* it;
	}

	snake_.clear();
	//delete all and clear massive
}

void Snake::Input(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up)
		dir_ = 0;
	if (key == sf::Keyboard::Right)
		dir_ = 1;
	if (key == sf::Keyboard::Down)
		dir_ = 2;
	if (key == sf::Keyboard::Left)
		dir_ = 3;
}

void Snake::Update()
{

}

void Snake::Render(sf::RenderWindow& window)
{
	for (auto it = snake_.begin(); it != snake_.end(); ++it)
	{
		body_.setPosition(68.5 + 35.f * (*it)->x_, 58.5 + 35.f * (*it)->y_);
		window.draw((*it)->body_);
	}	
}
