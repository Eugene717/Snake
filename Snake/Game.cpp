#include "Game.h"
#include "Snake.h"
#include "Fruit.h"
#include <random>
#include <SFML/Graphics.hpp>

Game::Game()
{
	gameStarted_ = gameEnded_ = false;
	score_ = 0;
	snake_ = new Snake();
	fruit_ = new Fruit();
	fruit_->Init(14, 7);

	font_.loadFromFile("arial.ttf");

	sf::RectangleShape* board = new sf::RectangleShape;
	board->setFillColor(sf::Color::Black);
	board->setSize(sf::Vector2f(701, 526));
	board->setOutlineThickness(50);
	board->setOutlineColor(sf::Color(80, 80, 80));
	board->setPosition(50, 40);
	objects_.push_back(board);

	sf::Text* score = new sf::Text("Score: " + std::to_string(score_), font_, 30);
	score->setFillColor(sf::Color::White);
	objects_.push_back(score);
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

void Game::EndGame()
{
	gameEnded_ = true;
	gameStarted_ = false;
	sf::Text* end;
	if (score_ == 3000)
		end = new sf::Text("You Lose!", font_, 30);
	else
		end = new sf::Text("You Win!", font_, 30);
	sf::Text* start = new sf::Text("Press any key to start a new game", font_, 30);

	end->setFillColor(sf::Color::White);
	end->setOrigin(end->getGlobalBounds().width / 2, end->getGlobalBounds().height / 2);
	end->setPosition(400, 250);

	start->setFillColor(sf::Color::White);
	start->setOrigin(start->getGlobalBounds().width / 2, start->getGlobalBounds().height / 2);
	start->setPosition(400, 300);

	objects_.push_back(end);
	objects_.push_back(start);
}

void Game::NewGame()
{
	score_ = 0;
	delete snake_;
	snake_ = new Snake();
	fruit_->Init(14, 7);
	dynamic_cast<sf::Text*>(objects_[1])->setString("Score: " + std::to_string(score_));
	objects_.pop_back();
	objects_.pop_back();
}

void Game::SpawnFruit()
{
	std::random_device rd;
	int x, y;
	while (true)
	{
		x = rd() % 20;
		y = rd() % 15;

		if (snake_->FreePlace(x, y))
		{
			score_ += 10;
			dynamic_cast<sf::Text*>(objects_[1])->setString("Score: " + std::to_string(score_));
			fruit_->Init(x, y);
			break;
		}
	}
}

void Game::Input(sf::Keyboard::Key key)
{
	if (!gameStarted_ && !gameEnded_)
		if (snake_->Input(key))
			gameStarted_ = true;
		else
			return;

	if (gameEnded_)
	{
		if (key)
		{
			gameEnded_ = false;
			NewGame();
			return;
		}
	}

	snake_->Input(key);
}

void Game::Update()
{
	if (gameStarted_)
	{
		if (!snake_->Update())
		{
			EndGame();
			return;
		}
		if (snake_->EatFruit())
		{
			if (score_ == 3000)
				EndGame();
			else
				SpawnFruit();
		}
	}
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	for (int i = 0; i < 2; i++)
	{
		window.draw(*objects_[i]);
	}

	fruit_->Render(window);
	snake_->Render(window);

	for (int i = 2; i < objects_.size(); i++)
	{
		window.draw(*objects_[i]);
	}
}
