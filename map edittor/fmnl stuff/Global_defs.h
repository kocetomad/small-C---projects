#pragma once
#include <SFML/Graphics.hpp>

//SOME SFML DEFS should've been here but many of them can't be global


sf::Clock cursror_clock;
sf::Clock keyboard_clock;
int CursorX = 0;
int CursorY = 0;
bool KeyPressed = false;
int grid[15][20];
