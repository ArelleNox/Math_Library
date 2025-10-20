#include "Score.h"

Score::Score() : font1{}, scoreText1(font1, "", 24), scoreText2(font1, "", 24), score1(0), score2(0){
	if (!font1.openFromFile("Font/questar_2/Questar.ttf")) {
		std::cerr << "Erreur : impossible de charger la police !" << std::endl;
	}

	scoreText1.setString(std::to_string(player1->getScore())); 
	scoreText1.setFillColor(sf::Color::White);
	scoreText1.setPosition(static_cast<sf::Vector2f>(ml::Vector2f{ 350.0f, 10.0f }));

	scoreText2.setString(std::to_string(player2->getScore()));
	scoreText2.setFillColor(sf::Color::White);
	scoreText2.setPosition(static_cast<sf::Vector2f>(ml::Vector2f{ 450.0f, 10.0f }));
}

void Score::draw(sf::RenderWindow& window) {
	window.draw(scoreText1);
}

void Score::IncrementeScore() {
	if (ball->getPosition().X() >= 800) {
		score1 = (player1->getScore() + 1);
		scoreText1.setString(std::to_string(player1->getScore()));
		ball->getShape().setPosition(static_cast<sf::Vector2f>(ml::Vector2f(400.0f, 300.0f)));
	}
	else if (ball->getPosition().X() <= 0) {
		score2 = (player2->getScore() + 1);
		scoreText2.setString(std::to_string(player2->getScore()));
		ball->getShape().setPosition(static_cast<sf::Vector2f>(ml::Vector2f(300.0f, 150.0f)));
	}
}