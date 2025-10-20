 #include "Game.h"

Game::Game() {}


void Game::run() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Pong");
    window.setFramerateLimit(60);

    ball = std::make_shared<Ball>(ml::Vector2f{400, 300}, ml::Vector2f{300.0f, 250.0f}); 
    player1 = std::make_shared<Player>(ml::Vector2f{30, 250}, ml::Vector2f{10, 100}, 300.0f, 1, 0);
    player2 = std::make_shared<Player>(ml::Vector2f{760, 250}, ml::Vector2f{10, 100}, 300.0f, 2, 0);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
        
        float deltaTime = clock.restart().asSeconds();

        sf::FloatRect ballBounds = ball->getShape().getGlobalBounds();
        sf::FloatRect p1Bounds = player1->getShape().getGlobalBounds();
        sf::FloatRect p2Bounds = player2->getShape().getGlobalBounds();

        // --- Collision avec le haut et le bas de la fenêtre ---
        if (ball->getPosition().Y() <= 0.0f ||
            ball->getPosition().Y() + ball->getRadius() * 2 >= 600.0f)
        {
            ml::Vector3<float> normal;

            if (ball->getPosition().Y() <= 0.0f)
                normal = ml::Vector3<float>(0.0f, 1.0f, 0.0f);
            else
                normal = ml::Vector3<float>(0.0f, -1.0f, 0.0f);

            ml::Vector3<float> reflection =
                ml::Vector3<float>::Reflect(ball->getVelocity().ToVector3(), normal);

            ball->setVelocity(ml::Vector2f::ToVector2(reflection));
        }

        if (ballBounds.findIntersection(p1Bounds))
        {
            float offset = (ball->getPosition().Y() + ball->getRadius()) -
                (player1->getPosition().Y() + player1->getSize().Y() / 2.0f);

            float maxAngle = 60.0f * (3.14159265f / 180.0f);
            float angle = (offset / (player1->getSize().Y() / 2.0f)) * maxAngle;

            ml::Vector2f newDir = ml::Vector2f(std::cos(angle), std::sin(angle));
            ball->setVelocity(newDir.Normalized() * ball->getVelocity().Magnitude());
        }


        if (ballBounds.findIntersection(p2Bounds))
        {
            float offset = (ball->getPosition().Y() + ball->getRadius()) -
                (player2->getPosition().Y() + player2->getSize().Y() / 2.0f);

            float maxAngle = 60.0f * (3.14159265f / 180.0f);
            float angle = (offset / (player2->getSize().Y() / 2.0f)) * maxAngle;

            ml::Vector2f newDir = ml::Vector2f(-std::cos(angle), std::sin(angle)); // inverse X
            ball->setVelocity(newDir.Normalized() * ball->getVelocity().Magnitude());
        }

        if (ball->getPosition().X() >= 800) {
			ball->getShape().setPosition(static_cast<sf::Vector2f>(ml::Vector2f(400.0f, 300.0f)));           ///// pk ca marche pas ???
			std::cout << ball->getPosition().X() << std::endl;
        }
        else if (ball->getPosition().X() <= 0) {
            ball->getShape().setPosition(static_cast<sf::Vector2f>(ml::Vector2f(300.0f, 150.0f)));
        }

        /*score.IncrementeScore();*/
		ball->update(deltaTime);                         ////////////////// Le Score est implémenter mais on a eu des problèmes pour l'afficher a cause d'un path incorrect non résolu 
        player1->update(deltaTime);                      /////////////// on ne peut donc pas voir son score et la balle ne revient pas au milieu apres un point du au fait que c'est mis au 
		player2->update(deltaTime);						 //////////// sein de la classe Score. on a bidouillé pour qu'elle reaparaisse quand meme independement du score mais bof

        // Draw
        window.clear();
		//score.draw(window);
		ball->draw(window);
        player1->draw(window);
        player2->draw(window);
        window.display();
    }
}