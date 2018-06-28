#include <SFML/Graphics.hpp>
#include <vector>
#include "misc_functions.h"
#include <chrono>
#include <thread>
using std::vector;


int main()
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds
	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Hello SFML", sf::Style::Default);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	

	sf::RectangleShape Ceiling(sf::Vector2f(800,300));
	sf::RectangleShape Floor(sf::Vector2f(800, 300));
	Ceiling.setPosition(0, 0);
	Floor.setPosition(0, 300);
	Ceiling.setFillColor(sf::Color(105, 105, 105));
	Floor.setFillColor(sf::Color(192, 192, 192));
	 
	


	sf::RectangleShape WALLS[16];





	sf::RectangleShape RayOne(sf::Vector2f(120, 1));
	sf::RectangleShape RayTwo(sf::Vector2f(120, 1));






	sf::CircleShape player;
	player.setPointCount(4);
	player.setRadius(5);

	player.setFillColor(sf::Color::Red);
	player.setPosition(50, 50);
	player.setOrigin(5, 5);


	sf::RectangleShape filled;
	filled.setSize(sf::Vector2f(10, 10));
	filled.setOutlineColor(sf::Color::White);
	filled.setOutlineThickness(1);
	filled.setFillColor(sf::Color::Green);

	sf::RectangleShape empty;
	empty.setSize(sf::Vector2f(10, 10));
	empty.setOutlineColor(sf::Color::White);
	empty.setOutlineThickness(1);
	empty.setFillColor(sf::Color::Black);





	int MAP[15][20]{
		1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	};

	///collisions
	struct hitbox collis[300];

 	for (int x = 0;x < 20;x++) {
		for (int y = 0;y < 15;y++) {
				if (MAP[y][x] == 1) {
					collis[objects].x = x*10;
					collis[objects].y = y*10;
					collis[objects].width = x*10+10;
					collis[objects].heighth = y*10 + 10;
					objects++;

				}


			

		}

	}





	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Ceiling);
		window.draw(Floor);
		
		



		for (int x = 0;x < 20;x++) {
			for (int y = 0;y < 15;y++) {
				switch (MAP[y][x]) {
				case 1:
					empty.setPosition(x * 10, y * 10);
					window.draw(empty);
					break;
				case 0:
					filled.setPosition(x * 10, y * 10);
					window.draw(filled);
					break;


				}

			}

		}
		for (int i = 0; i < objects; i++) {
			if (player.getGlobalBounds().left+10 >= collis[i].x && player.getGlobalBounds().left <= collis[i].x + 10 && player.getGlobalBounds().top+10 >= collis[i].y && player.getGlobalBounds().top <= collis[i].y + 10) {

				collison = true;
			}
		}
		RayOne.setSize(sf::Vector2f(RayOneLength, 1));
		RayTwo.setSize(sf::Vector2f(100, 1));




		//>REYCAST ENDPOINT DEBUG
		/////<
		window.draw(player); 
		KeyboardInput(player, RayOne );
		
		
		RayCastOne(player, RayOne, collis, window);





		for (int i = 0;i < 12;i++) {

			WALLS[i].setSize(sf::Vector2f(70,200));
			WALLS[i].setPosition(i * 70, 200 );
			WALLS[i].setFillColor(sf::Color(100, 0,100));

			window.draw(WALLS[i]);
		}
		/*float WALL1ysize = 200 - RayCast1;
		WALL1.setPosition(WALL1.getPosition().x, WALL1ysize);
		WALL1.setSize(sf::Vector2f(40, WALL1ysize+100));*/


		window.draw(RayOne);

		window.display();
	}


	return 0;
}