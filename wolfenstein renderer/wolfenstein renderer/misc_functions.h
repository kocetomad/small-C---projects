#pragma once
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
float speedX=50;
float speedY = 50;
bool collison = false;


int objects = 0;

bool RayOneCollision = false;
float RayOneLength = 0;
float RayCast1 = 0;

bool RayTwoCollision = false;
float RayTwoLength = 0;
float RayCast2 = 0;



int RayAngle = -20;
float RaySweep[8] = { 0 };
int RaySweepIterator=0;


struct hitbox {
	int x;
	int y;
	int width;
	int heighth;
};


int** create2DArray(int *arr)
{
	int** array2D=0;
	array2D = new int*[15];

	for (int h = 0; h < 15; h++)
	{
		array2D[h] = new int[20];

		for (int w = 0; w < 20; w++)
		{
		
			array2D[h][w] = arr[h*15+w];
		}
	}


	
	return array2D;
}






void RayCastOne(sf::CircleShape &player, sf::RectangleShape &RayOne ,struct hitbox *collis , sf::RenderWindow &window) {
		float x = speedX;
	float y = speedY;
	RayOne.setPosition(x, y);
	float rotation = player.getRotation();
	
	do {
		RayOne.setRotation(rotation + RayAngle);

		if (player.getRotation() >= 0 - RayAngle && player.getRotation() <= 90 - RayAngle) {
			//std::cout << player.getPosition().x + RayOne.getGlobalBounds().width << "     ," << player.getPosition().y + RayOne.getGlobalBounds().height << "    ," << player.getRotation() << std::endl;
			for (int i = 0; i < objects; i++) {
				if (player.getPosition().x + RayOne.getGlobalBounds().width >= collis[i].x && player.getPosition().x + RayOne.getGlobalBounds().width <= collis[i].x + 10
					&& player.getPosition().y + RayOne.getGlobalBounds().height >= collis[i].y && player.getPosition().y + RayOne.getGlobalBounds().height <= collis[i].y + 10) {
					RayOneCollision = true;
					RayCast1 = RayOneLength;
					RaySweep[RaySweepIterator] = RayCast1;
					RaySweepIterator++;


					RayOneLength = 0;


				
				}
				else {
					RayOneCollision = false;
				}
			}
		}
		 if(player.getRotation() > 90  && player.getRotation() <= 180 ) {
			//std::cout << player.getPosition().x - RayOne.getGlobalBounds().width << "     ," << player.getPosition().y + RayOne.getGlobalBounds().height << "    ," << player.getRotation() << std::endl;
			for (int i = 0; i < objects; i++) {
				if (player.getPosition().x - RayOne.getGlobalBounds().width >= collis[i].x && player.getPosition().x - RayOne.getGlobalBounds().width <= collis[i].x + 10
					&& player.getPosition().y + RayOne.getGlobalBounds().height >= collis[i].y && player.getPosition().y + RayOne.getGlobalBounds().height <= collis[i].y + 10) {
					RayOneCollision = true;
					RayCast1 = RayOneLength;
					RaySweep[RaySweepIterator] = RayCast1;
					RaySweepIterator++;

					RayOneLength = 0;


				

				}
				else {
					RayOneCollision = false;
				}
			}
		}
		 if(player.getRotation() > 180  && player.getRotation() <= 270 ) {
			//std::cout << player.getPosition().x - RayOne.getGlobalBounds().width << "     ," << player.getPosition().y - RayOne.getGlobalBounds().height << "    ," << player.getRotation() << std::endl;
			for (int i = 0; i < objects; i++) {
				if (player.getPosition().x - RayOne.getGlobalBounds().width >= collis[i].x && player.getPosition().x - RayOne.getGlobalBounds().width <= collis[i].x + 10
					&& player.getPosition().y - RayOne.getGlobalBounds().height >= collis[i].y && player.getPosition().y - RayOne.getGlobalBounds().height <= collis[i].y + 10) {
					RayOneCollision = true;
					RayCast1 = RayOneLength;
					RaySweep[RaySweepIterator] = RayCast1;
					RaySweepIterator++;

					RayOneLength = 0;


				}
				else {
					RayOneCollision = false;
				}
			}

		}
		 if(player.getRotation() > 270 && player.getRotation() <= 360 ) {
			//std::cout << player.getPosition().x + RayOne.getGlobalBounds().width << "     ," << player.getPosition().y - RayOne.getGlobalBounds().height << "    ," << player.getRotation() << std::endl;
			for (int i = 0; i < objects; i++) {
				if (player.getPosition().x + RayOne.getGlobalBounds().width >= collis[i].x && player.getPosition().x + RayOne.getGlobalBounds().width <= collis[i].x + 10
					&& player.getPosition().y - RayOne.getGlobalBounds().height >= collis[i].y && player.getPosition().y - RayOne.getGlobalBounds().height <= collis[i].y + 10) {
					RayOneCollision = true;
					RayCast1 = RayOneLength;
					RaySweep[RaySweepIterator] = RayCast1;
					RaySweepIterator++;

					RayOneLength = 0;

				}
				else {
					RayOneCollision = false;
				}
			}
		}
		 std::cout << RaySweepIterator << std::endl;

		RayAngle += 5;
		window.draw(RayOne);
	} while (RayAngle<20);
	RaySweepIterator = 0;
	RayAngle = -20;
	if (!RayOneCollision) {
		RayOneLength += 2;
	}
}







void MoveForward(sf::CircleShape &player) {
	
	float directionX = (float)cos((player.getRotation()*M_PI)/180);
	float directionY = (float)sin((player.getRotation()*M_PI) / 180);
	speedX += (1 * directionX)/50;
	speedY += (1 * directionY)/50;
	

	player.setPosition((speedX), (speedY) );
	
}




void KeyboardInput(sf::CircleShape &player, sf::RectangleShape &RayOne) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		collison = false;

		player.rotate(-0.4);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		collison = false;
		player.rotate(0.4);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (!collison) {
			MoveForward(player);
			RayOneLength -= 0.1;
	
		}
	}


}

