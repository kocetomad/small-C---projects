#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Global_defs.h"



void DrawUi(sf::RenderWindow &window) {
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	Sprites.setCharacterSize(30);
	Sprites.setStyle(sf::Text::Bold);
	Sprites.setPosition(500, 500);
	window.draw(Sprites);


}