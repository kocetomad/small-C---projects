#pragma once
#include <SFML/Graphics.hpp>
#include "Global_defs.h"
#include <iostream>
#include <fstream>

void Export() {
	std::ofstream outfile("MAP.txt");
	for (int y = 0;y < 15;y++) {
		for (int x = 0;x < 20;x++) {

			outfile << grid[y][x];
			outfile << ",";

		}
		outfile << "\n";

	}
	outfile.close();
	keyboard_clock.restart();
}


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

void KeyboardInput(sf::Sprite &CurosorSprite) {
	if (keyboard_clock.getElapsedTime().asSeconds() > 0.25f) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			KeyPressed = true;
			if (CursorX == 0) {
				CursorX = 32 * 19;
			}
			else {
				CursorX -= 32;
			}
			CurosorSprite.setPosition(CursorX, CursorY);
			keyboard_clock.restart();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			KeyPressed = true;
			if (CursorX == 32 * 19) {
				CursorX = 0;
			}
			else {
				CursorX += 32;
			}
			CurosorSprite.setPosition(CursorX, CursorY);
			keyboard_clock.restart();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			KeyPressed = true;
			if (CursorY == 0) {
				CursorY = 32 * 14;
			}
			else {
				CursorY -= 32;
			}
			CurosorSprite.setPosition(CursorX, CursorY);
			keyboard_clock.restart();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			KeyPressed = true;
			if (CursorY == 32 * 14) {
				CursorY = 0;
			}
			else {
				CursorY += 32;
			}
			CurosorSprite.setPosition(CursorX, CursorY);
			keyboard_clock.restart();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			grid[CursorY / 32][CursorX / 32] = 1;
			keyboard_clock.restart();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			grid[CursorY / 32][CursorX / 32] = 0;
			keyboard_clock.restart();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			Export();

		}

	}

}

