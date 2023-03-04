#include <SFML\Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
	window.setFramerateLimit(60);
	Game game;

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		clock.restart();
		while (clock.getElapsedTime().asMilliseconds() <= 120)
			if (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
				if (event.type == sf::Event::KeyReleased)
				{
					game.Input(event.key.code);
					break;
				}
			}

		sf::sleep(sf::milliseconds(120 - clock.getElapsedTime().asMilliseconds()));

		game.Update();

		game.Render(window);
	}

	return 0;
}
