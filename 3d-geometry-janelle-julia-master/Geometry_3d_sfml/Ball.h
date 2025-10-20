#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"

class Ball
{
protected:
	sf::CircleShape ball;
	ml::Vector2f position;
	ml::Vector2f velocity;

	sf::Time time;
	bool isStarted = false;

public:
	Ball(ml::Vector2f Pos, ml::Vector2f velocity);

	void update(float delataTime);
	void draw(sf::RenderWindow& window);

	void Move(float deltaTime);
	
	ml::Vector2f getPosition();
	float getRadius();
	ml::Vector2f setVelocity(ml::Vector2f newVelocity);
	ml::Vector2f getVelocity();
	sf::CircleShape& getShape();

};

