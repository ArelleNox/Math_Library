#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include "Score.h"
#include "Ball.h"

class Game {
protected:
    sf::RenderWindow window;
    sf::VideoMode video;
    sf::Clock clock;
    /*Score score;*/

    std::shared_ptr<Ball> ball;
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
   
    ml::Vector3<float> normal;

public:
    Game();
    void run();
   
};
