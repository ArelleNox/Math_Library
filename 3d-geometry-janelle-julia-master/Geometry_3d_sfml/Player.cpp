#include "Player.h"

Player::Player(const ml::Vector2f& startPos, const ml::Vector2f& size, float speed, int id, int score) : position(startPos), size(size), speed(speed), id(id), score(score) {
	shape.setSize(sf::Vector2f(size.X(), size.Y()));
	shape.setFillColor(sf::Color::White);
	shape.setPosition(static_cast<sf::Vector2f>(ml::Vector2f(position.X(), position.Y())));
}

void Player::update(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && id == 1) {                    
		position = position + ml::Vector2f(0.0f, -speed * deltaTime);
		if (position.Y() < 0.0f) {
			position = ml::Vector2f(position.X(), 0.0f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && id == 1) {
		position = position + ml::Vector2f(0.0f, speed * deltaTime);
		if (position.Y() + size.Y() > 600.0f) {
			position = ml::Vector2f(position.X(), 600.0f - size.Y());
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && id == 2){
		position = position + ml::Vector2f(0.0f, speed * deltaTime);
		if (position.Y() + size.Y() > 600.0f) {
			position = ml::Vector2f(position.X(), 600.0f - size.Y());
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && id == 2) {
		position = position + ml::Vector2f(0.0f, -speed * deltaTime);
		if (position.Y() < 0.0f) {
			position = ml::Vector2f(position.X(), 0.0f);
		}
	}
	shape.setPosition(static_cast<sf::Vector2f>(ml::Vector2f(position.X(), position.Y())));
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

int Player::getId() {
	return id;
}

ml::Vector2f Player::getPosition() {
	return position;
}

ml::Vector2f Player::getSize() {
	return size;
}

int Player::getScore() {
	return score;
}

float Player::X() {
	return position.X();
}

float Player::Y() {
	return position.Y();
}

sf::RectangleShape& Player::getShape() {
	return shape;
}

void Player::incrementPlyerScore() {
	score++;
}