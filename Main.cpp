#include <iostream>
#include <array>
#include "GameObject.h"
#include "PlayerShip.h"
#include "Structs.h"
#include <string>
#include <SFML/Graphics.hpp>

//std::wcout << newYVel;
int checkWasd()
{
	int cInput;

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

	return cInput;
}

bool checkFire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//multi dimensional array of movement patterns for AI, velocity to be changed incrementally to make non linear movement
//stores 8 arrays of 12 movements each
velocity pathing[8][12] = {
	//0) accelerates right to left while slowly moving down
	{(1, 0.5), (2, 0.5), (1, 0.5), (0, 0.5), (-1, 0.5), (-2, 0.5), (-1, 0.5), (0, 0.5), (1, 0.5), (2, 0.5), (1, 0.5), (0, 0.5)},
	//1)
	{(1, 1), (1, 2), (1, 0), (-1, -1), (-1, -2), (-1, -1), (1, 0), (1, 1), (1, 2), (1, 0), (1, 1), (1, 2)},
	//2) moves left to right, comes in from right side of the screen (doesn't move vertically)
	{(-1, 0), (-1, 0), (-1, 0), (-1, 0), (-1, 0), (-1, 0), (1, 0), (1, 0), (1, 0), (-1, 0), (-1, 0), (-1, 0)},
	//3) shaped loop (recurrable)
	{(-2, 1), (-1, 1), (-1, 2), (1, 2), (1, 1), (2, 1), (2, -1), (1, -2), (1, -2), (-1, -1), (-2, -1), (-1, -1)},
	//4) moves up and down the screen moving to the right after each direction change
	{(0, 2), (0, 2), (1, -1), (0, -2), (0, -2), (1, 1), (0, 2), (0, 2), (1, -1), (0, -2), (0, -2), (1, 1)},
	//5)
	{(1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1)},
	//6)
	{(1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1)},
	//7)
	{(0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1)},
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works");

	sf::Clock shotClock;

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Magenta);




	//sf::Texture texture;
	 
	//Currently causes crash as permission not available too access resource
	/*

	if (!texture.loadFromFile("Res\scrollBackgroundOne.jpg"))
	{
		std::wcout << "can't find resource";

		system("pause");
	}
	*/

	int cInput = 0;
	PlayerShip test =  PlayerShip();

	std::array<Projectile, 20> currentProjectiles;
	int projectileCount = 0;


	std::array<sf::CircleShape, 20> drawnShapes;


	//sf::Sprite background;
	//background.setTexture(texture);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed)
				window.close();
		}



		cInput = checkWasd();

		if (checkFire())
		{
			if (test.getFireDelay() < shotClock.getElapsedTime().asMilliseconds())
			{
				currentProjectiles[projectileCount] = test.shoot();

				drawnShapes[projectileCount] = sf::CircleShape::CircleShape(10.f);
				projectileCount++;
				shotClock.restart();

				if (projectileCount > 19)
				{
					std::wcout << currentProjectiles[projectileCount - 1].getYPos();
					projectileCount = 0;
				}
			}
		}


		test.move(cInput);

		test.updatePosition();


		for (Projectile projectile : currentProjectiles)
		{
			projectile.updatePosition();
			//hit detection for projectiles goes here
			for (int i = 0; i < currentProjectiles.size(); i++)
			{
				drawnShapes[i].setFillColor(sf::Color::Green);
				drawnShapes[i].setPosition(sf::Vector2f(currentProjectiles[i].getXPos(), currentProjectiles[i].getYPos()));
			}

		}


	

		shape.setPosition(sf::Vector2f(test.getXPos(), test.getYPos()));

	
		window.clear();
		//window.draw(background);
		window.draw(shape);

		for (int i = 0; i < drawnShapes.size(); i++)
		{
			currentProjectiles[i].updatePosition();
			window.draw(drawnShapes[i]);
		}

		window.display();
	}

	return 0;
}
