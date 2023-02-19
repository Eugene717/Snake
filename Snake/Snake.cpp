#include "Snake.h"
#include "Fruit.h"

int Snake::dir_ = 1;
int Snake::fruitX_, Snake::fruitY_;
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

		fruitX_ = 14;
		fruitY_ = 7;

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

bool Snake::FreePlace(const int x, const int y) const
{
	for (auto it = snake_.begin(); it != snake_.end(); ++it)
	{
		if ((*it)->x_ == x && (*it)->y_ == y)
			return false;
	}
	fruitX_ = x;
	fruitY_ = y;
	return true;
}

bool Snake::EatFruit() const
{
	bool temp = eatFruit_;
	eatFruit_ = false;
	return temp;
}

bool Snake::Input(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up)
	{
		if (dir_ != 2)
		{
			dir_ = 0;
			return true;
		}
	}
	if (key == sf::Keyboard::Right)
	{
		if (dir_ != 3)
		{
			dir_ = 1;
			return true;
		}
	}
	if (key == sf::Keyboard::Down)
	{
		if (dir_ != 0)
		{
			dir_ = 2;
			return true;
		}
	}
	if (key == sf::Keyboard::Left)
	{
		if (dir_ != 1)
		{
			dir_ = 3;
			return true;
		}
	}
	return false;
}

bool Snake::Update()
{
	int tempx = x_;
	int tempy = y_;

	switch (dir_)   //move head
	{
	case 0:   //up
		if (y_ - 1 < 0)
			return false;
		else
			--y_;
		break;
	case 1:   //right
		if (x_ + 1 > 19)
			return false;
		else
			++x_;
		break;
	case 2:   //down
		if (y_ + 1 > 14)
			return false;
		else
			++y_;
		break;
	case 3:   //left
		if (x_ - 1 < 0)
			return false;
		else
			--x_;
		break;
	default:
		break;
	}

	for (auto it = snake_.rbegin(); it != --snake_.rend(); ++it)   //move tail
	{
		(*it)->x_ = (*it)->prev_->x_;
		(*it)->y_ = (*it)->prev_->y_;
	}
	auto it = ++snake_.begin();
	(*it)->x_ = tempx;
	(*it)->y_ = tempy;

	if (x_ == fruitX_ && y_ == fruitY_)   //eat fruit
	{
		Snake* snake = new Snake(snake_.back());
		eatFruit_ = true;
		return true;
	}

	for (auto it = ++snake_.begin(); it != snake_.end(); ++it)   //bite tail
	{
		if (x_ == (*it)->x_ && y_ == (*it)->y_)
			return false;
	}

	return true;
}

void Snake::Render(sf::RenderWindow& window)
{
	for (auto it = snake_.begin(); it != snake_.end(); ++it)
	{
		body_.setPosition(68.5 + 35.f * (*it)->x_, 58.5 + 35.f * (*it)->y_);
		window.draw((*it)->body_);
	}	
}
