#include <iostream>
#include "GameObject.h"
#include "PlayerShip.h"
#include <string>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works");
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Magenta);

	//int x = 0;
	//int y = 0;
	int cInput = 0;
	PlayerShip test =  PlayerShip();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();
		}

		//input for negative x direction
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			//input for negative x and positive y
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				cInput = 4;
			}
			//input for negative x and negative y
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				cInput = 6;
			}
			//input for negative x neutral y
			else
			{
				cInput = 2;
			}
		}
		//positive x direction
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			//input for positive x and positive y
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				cInput = 3;
			}
			//input for positive x and negative y
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				cInput = 5;
			}
			//input for positive x and neutral y
			else
			{
				cInput = 1;
			}
		}
		//neutral x input values
		else
		{
			//input for neutral x and positive y
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				cInput = 7;
			}
			//input for neutral x and negative y
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				cInput = 8;
			}
			//blank input
			else
			{
				cInput = 0;
			}
		}

		test.move(cInput);
		test.updatePosition();

		/**
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			if (x > 0)
				x--;
			else
				x = 1920;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			if (x < 1920)
				x++;
			else
				x = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			if (y < 1080)
				y++;
			else
				y = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (y > 0)
				y--;
			else
				y = 1080;
		}
	


		shape.setPosition(sf::Vector2f(x, y));
		**/

		//std::wcout << test.getXPos();
		if (test.getXPos() > 1920 / 2)
			std::wcout << "moved";

	

		shape.setPosition(sf::Vector2f(test.getXPos(), test.getYPos()));

	
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}