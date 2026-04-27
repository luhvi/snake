#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

enum class Direction
{
	up,
	down,
	left,
	right
};

int main()
{
	sf::RenderWindow window(sf::VideoMode({600, 600}), "Snake");
	sf::RectangleShape shape({20.f, 20.f});
	shape.setFillColor(sf::Color::Green);

	float x{580.f};
	float y{580.f};

	Direction currDirection{Direction::up};

	shape.setPosition({x, y});

	while (window.isOpen())
	{
		using enum Direction;

		shape.setPosition({x, y});
		Sleep(100);

		switch (currDirection)
		{
			case up:
				if (y > 0.f)
					y -= 20.f;
				else
					y = 580.f;
				break;
			case down:
				if (y < 580.f)
					y += 20.f;
				else
					y = 0.f;
				break;
			case left:
				if (x > 0.f)
					x -= 20.f;
				else
					x = 580.f;
				break;
			case right:
				if (x < 580.f)
					x += 20.f;
				else
					x = 0.f;
				break;
		}

		while (const std::optional event = window.pollEvent())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				currDirection = up;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				currDirection = down;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
				currDirection = left;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
				currDirection = right;

			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
