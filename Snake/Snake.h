#pragma once
#include <list>
#include <SFML/Graphics.hpp>

class Fruit;

class Snake
{
	static std::list<Snake*> snake_;
	Snake const* prev_;
	static bool eatFruit_;
	static int fruitX_, fruitY_;

	static int dir_;
	int x_, y_;

	static sf::RectangleShape body_;

	Snake(int x, int y);
public:
	Snake(Snake const* prev = nullptr);
	~Snake();
	bool FreePlace(const int x, const int y) const;
	bool EatFruit() const;
	bool Input(sf::Keyboard::Key key);
	bool Update();
	void Render(sf::RenderWindow& window);
};

