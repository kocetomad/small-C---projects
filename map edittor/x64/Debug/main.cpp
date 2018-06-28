
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "misc_functions.h"
#include "Global_defs.h"
#include "Button.h"

//#include "UI.h"
int main()
{
	
	sf::IntRect rectSourceSprite(0, 0, 32, 32);
	sf::RectangleShape empty;
	sf::Texture texture;
	sf::Texture Brown;
	sf::Texture BrownBig;
	sf::Texture RedBig;

	sf::Sprite RedBricks;
	sf::Sprite BrownBricks;
	sf::Sprite RedBricksBig;
	sf::Sprite BrownBricksBig;

	sf::Sprite Background;
	sf::Texture Background_texture;
	Button test;
	sf::Texture cursor;
	sf::Sprite CurosorSprite(cursor, rectSourceSprite);
	cursor.loadFromFile("cursor.png");


	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Map Edittor", sf::Style::Default);
	
	empty.setSize(sf::Vector2f(32, 32));
	empty.setOutlineColor(sf::Color::White);
	empty.setOutlineThickness(1);
	empty.setFillColor(sf::Color::Black);



	(sf::Vector2f(120, 50));
	texture.loadFromFile("BrickFireRed.png");
	RedBricks.setTexture(texture);

	Brown.loadFromFile("BrickBrown.png");
	BrownBricks.setTexture(Brown);

	RedBig.loadFromFile("RedBrick_button.png");
	RedBricksBig.setTexture(RedBig);

	BrownBig.loadFromFile("BrownBrick_button.png");
	BrownBricksBig.setTexture(BrownBig);


	//
	Background_texture.loadFromFile("bckg.png");
	Background.setTexture(Background_texture);

	//UI
	sf::Font font;
	sf::Text Sprites("Sprites:", font);
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	Sprites.setCharacterSize(30);
	Sprites.setStyle(sf::Text::Bold);
	Sprites.setPosition(660, 5);
	//UI


	//INITIAL GRID fill 
	for (int x = 0;x < 20;x++) {
		for (int y = 0;y < 15;y++) {
			grid[y][x] = 0;

		}

	}
	// GRID ENDS

	

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();


		window.draw(Background);
		test.SetButtonPosition(window,RedBricksBig, 685, 50);
		test.SetButtonPosition(window, BrownBricksBig, 685, 150);

		if (test.GetButtonState(RedBricksBig, window)) {
			//std::cout << 1;
			window.draw(Sprites);
		}
		KeyboardInput(CurosorSprite);
				


		for (int x = 0;x < 20;x++) {
			for (int y = 0;y < 15;y++) {
				switch (grid[y][x]) {
					case 1:
					RedBricks.setPosition(x * 32, y * 32);
					window.draw(RedBricks);
					break;
					case 0:
					empty.setPosition(x * 32, y * 32);
					window.draw(empty);
					break;


				}

			}

		}

		//CURSOR ANIMATION STARTS 
		if (cursror_clock.getElapsedTime().asSeconds() > 0.2f) {
			if (rectSourceSprite.left == 128) {
				rectSourceSprite.left = 0;
			}
			else {
				rectSourceSprite.left += 32;
			}
			CurosorSprite.setTextureRect(rectSourceSprite);
			cursror_clock.restart();
		}
		//CURSOR ANIMATION ENDS 
		window.draw(CurosorSprite);
		window.display();

	}

	return 0;
}



