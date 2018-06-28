#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>


class Button {
public:

	void SetButtonPosition(sf::RenderWindow &window,sf::Sprite & ButtonSprite,int x,int y);
	bool GetButtonState(sf::Sprite &ButtonSprite, sf::RenderWindow &window);
	void SetButtonOutline(sf::Sprite &ButtonSprite, sf::RenderWindow &window);



};