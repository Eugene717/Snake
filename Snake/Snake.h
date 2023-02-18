#pragma once
#include <list>
#include <SFML/Graphics.hpp>

class Fruit;

class Snake
{
	static std::list<Snake*> snake_;
	Snake const* prev_;
	static bool eatFruit_;

	static int dir_;
	int x_, y_;

	static sf::RectangleShape body_;

	Snake(int x, int y);
public:
	Snake(Snake const* prev = nullptr);
	~Snake();
	void Input(sf::Keyboard::Key key);
	void Update();
	void Render(sf::RenderWindow& window);
};

