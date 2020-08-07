// iD Tech Game Plan - SFML Code
#include "Ball.h"
#include "Bat.h"

#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "ID Pong");

	float batWidth = 200;
	float batHeight = 10;
	Bat bat(windowWidth / 2, windowHeight - 20, batWidth, batHeight, 0.5f, Color::Black);

	float ballWidth = 20;
	float ballHeight = 20;
	Ball ball(windowWidth / 2, 1, ballWidth, ballHeight, Color::Red);

	bool movingLeft = false;
	bool movingRight = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Left) {
					movingLeft = true;
				}

				if (event.key.code == sf::Keyboard::Right) {
					movingRight = true;
				}
			}

			if (event.type == sf::Event::KeyReleased) {

				if (event.key.code == sf::Keyboard::Left) {
					movingLeft = false;
				}

				if (event.key.code == sf::Keyboard::Right) {
					movingRight = false;
				}
			}
		}

		if (movingLeft) {
			bat.MoveLeft();
		}
		if (movingRight) {
			bat.MoveRight();
		}

		FloatRect ballPos = ball.GetPosition();

		if (ballPos.top < 0) {
			ball.ReboundBat();
		}
		else if (ballPos.top > windowHeight) {
			ball.HitBottom();
		}
		else if (ballPos.left < 0 || ballPos.left + ballWidth > windowWidth) {
			ball.ReboundSide();
		}
		else if (ballPos.intersects(bat.GetPosition())) {
			ball.ReboundBat();
		}

		ball.Update();
		bat.Update();

		window.clear(Color(3, 232, 252, 255));
		window.draw(bat.GetShape());
		window.draw(ball.GetShape());
		window.display();
	}
}
