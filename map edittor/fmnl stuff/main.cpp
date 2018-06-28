
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
	//int testARR[] = {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	sf::IntRect rectSourceSprite(0, 0, 32, 32);
	sf::RectangleShape empty;
	sf::Texture texture;
	sf::Texture Brown;
	sf::Texture BrownBig;
	sf::Texture RedBig;
	sf::Texture Export_texture;


	sf::Sprite RedBricks;
	sf::Sprite BrownBricks;
	sf::Sprite RedBricksBig;
	sf::Sprite BrownBricksBig;
	sf::Sprite ExportButton;
	//create2DArray(testARR);


	//int** my2DArray = create2DArray(testARR);





	/*for (int y = 0;y < 15;y++) {
		for (int x = 0;x < 20;x++) {
			std::cout << my2DArray[y][x] << std::endl;
		}
	}*/










	sf::Sprite Background;
	sf::Texture Background_texture;
	Button ButtonInst;
	sf::Texture cursor;
	sf::Sprite CurosorSprite(cursor, rectSourceSprite);
	cursor.loadFromFile("cursor.png");


	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Map Edittor", sf::Style::Default);
	
	empty.setSize(sf::Vector2f(32, 32));
	empty.setOutlineColor(sf::Color::White);
	empty.setOutlineThickness(1);
	empty.setFillColor(sf::Color::Black);

	Export_texture.loadFromFile("EXPORT BUTTON.png");
	ExportButton.setTexture(Export_texture);

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
		ButtonInst.SetButtonPosition(window,RedBricksBig, 685, 50);
		ButtonInst.SetButtonPosition(window, BrownBricksBig, 685, 150);
		ButtonInst.SetButtonPosition(window, ExportButton, 20, 510);
		window.draw(Sprites);


		if (ButtonInst.GetButtonState(RedBricksBig, window)) {
			//std::cout << 1;
			window.draw(Sprites);
		}
		if (ButtonInst.GetButtonState(ExportButton, window)) {
			//std::cout << 1;
			Export();
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



