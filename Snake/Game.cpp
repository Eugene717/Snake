#include "Game.h"
#include "Snake.h"
#include "Fruit.h"
#include <random>
#include <SFML/Graphics.hpp>

Game::Game()
{
	snake_ = new Snake();
	fruit_ = new Fruit();
	fruit_->Init(14, 7);

	sf::RectangleShape* board = new sf::RectangleShape;
	board->setFillColor(sf::Color::Black);
	board->setSize(sf::Vector2f(701, 526));
	board->setOutlineThickness(50);
	board->setOutlineColor(sf::Color(80, 80, 80));
	board->setPosition(50, 40);
	objects_.push_back(board);
}

Game::~Game()
{
	delete snake_;
	delete fruit_;

	for (int i = 0; i < objects_.size(); i++)
	{
		delete objects_[i];
	}
	objects_.clear();
}

void Game::SpawnFruit()
{
	std::random_device rd;
	int x, y;
	while (true)
	{
		x = rd() % 20;
		y = rd() % 15;

		

		fruit_->Init(x, y);
	}
}

void Game::Input(sf::Keyboard::Key key)
{
	snake_->Input(key);
}

void Game::Update()
{
	snake_->Update();
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	for (int i = 0; i < objects_.size(); i++)
	{
		window.draw(*objects_[i]);
	}

	fruit_->Render(window);
	snake_->Render(window);
}
