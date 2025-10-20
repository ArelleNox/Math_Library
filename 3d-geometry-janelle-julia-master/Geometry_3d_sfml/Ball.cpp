#include "Ball.h"

Ball::Ball(ml::Vector2f pos, ml::Vector2f velocity) : position(pos), velocity(velocity) {
	ball.setRadius(10.0f);
	ball.setFillColor(sf::Color::Magenta);
	ball.setPosition(static_cast<sf::Vector2f>(pos));
}
void Ball::update(float deltaTime) {
	Move(deltaTime);
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(ball);
}

void Ball::Move(float deltaTime) {

	position = position + ml::Vector2f(velocity.X(), velocity.Y()) * deltaTime;
	ball.setPosition(static_cast<sf::Vector2f>(position));
}

ml::Vector2f Ball::getPosition() {
	return position;
}

float Ball::getRadius() {
	return ball.getRadius();
}

ml::Vector2f Ball::setVelocity(ml::Vector2f newVelocity) {
	velocity = newVelocity;
	return velocity;
}

ml::Vector2f Ball::getVelocity() {
	return velocity;
}

sf::CircleShape& Ball::getShape() {
	return ball;
}

