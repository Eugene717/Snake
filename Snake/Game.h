#pragma once
#include <SFML/Graphics.hpp>
class Snake;
class Fruit;

class Game
{
	Snake* snake_;
	Fruit* fruit_;
	std::vector<sf::Drawable*> objects_;
	bool gameStarted;

	void SpawnFruit();
public:
	Game();
	~Game();
	void Input(sf::Keyboard::Key key);
	void Update();
	void Render(sf::RenderWindow& window);
};

