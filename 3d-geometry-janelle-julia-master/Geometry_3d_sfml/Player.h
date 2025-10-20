#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

using namespace ml;

class Player{
protected:
	sf::RectangleShape shape;
	ml::Vector2f position;
	ml::Vector2f size;
	float speed;
	int id;
	int score;

public:
	Player(const ml::Vector2f& startPos, const ml::Vector2f& size, float speed, int id, int score);

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);


	int getId();
	ml::Vector2f getPosition();
	ml::Vector2f getSize();
	int getScore();
	float X();
	float Y();
	sf::RectangleShape& getShape();
	void incrementPlyerScore();
};