#include <SFML\Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
	window.setFramerateLimit(10);
	Game game;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				game.Input(event.key.code);
		}

		game.Update();

		game.Render(window);
		window.display();
	}

	return 0;
}
