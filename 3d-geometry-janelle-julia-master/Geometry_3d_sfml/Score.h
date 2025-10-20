#pragma once
#include "Player.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>

class Score {
protected:
	sf::Font font1;
	sf::Text scoreText1;
	sf::Text scoreText2;

	int score1;
	int score2;

	std::shared_ptr<Ball> ball;
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
public:
	Score();
	void draw(sf::RenderWindow& window);

	void IncrementeScore();
};

