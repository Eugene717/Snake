#pragma once
#include <list>
#include <SFML/Graphics.hpp>

class Fruit;

class Snake
{
	static std::list<Snake> snake_;
	Snake const* prev_;

	static int dir_;
	int x_, y_;

	static sf::Texture texture_;
	sf::Sprite sprite_;
public:
	Snake(Snake const* prev = nullptr);
	~Snake();
	void Input();
	void Update();
	void Render(sf::RenderWindow& window);
};

