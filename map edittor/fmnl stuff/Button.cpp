#include "Button.h"



void Button::SetButtonPosition(sf::RenderWindow &window,sf::Sprite &ButtonSprite, int x, int y)
{
	ButtonSprite.setPosition(x, y);
	window.draw(ButtonSprite);
	
}

bool Button::GetButtonState(sf::Sprite &ButtonSprite, sf::RenderWindow &window)
{
	sf::Vector2i MouselocalPosition = sf::Mouse::getPosition(window); // window is a sf::Window
	sf::FloatRect temp=ButtonSprite.getGlobalBounds();

	if (MouselocalPosition.x >= temp.left && MouselocalPosition.x <= temp.width+ temp.left && MouselocalPosition.y >= temp.top && MouselocalPosition.y <= temp.height+ temp.top && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		ButtonSprite.setColor(sf::Color(192, 192, 192));
		return true;
	}
	else {
		ButtonSprite.setColor(sf::Color::White);

		return false;
	}
}

void Button::SetButtonOutline(sf::Sprite &ButtonSprite, sf::RenderWindow &window)
{
	sf::FloatRect temp = ButtonSprite.getGlobalBounds();
	sf::RectangleShape outline;
	outline.setSize(sf::Vector2f(temp.width, temp.height));
	outline.setOutlineColor(sf::Color::Red);
	outline.setFillColor(sf::Color::Transparent);
	outline.setPosition(temp.left, temp.top);
	outline.setOutlineThickness(1);
	window.draw(outline);

}
