#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class Menu
{
private:
	std::vector<Button> buttons;
	sf::RectangleShape menuBack;
	float width;
	float height;

	float PositionX;
	float PositionY;

	float spacing;
public:
	Menu(sf::Font&, float, float, float, float, float);
	std::vector<Button>& getButtons();
	void drawMenu(sf::RenderWindow&);
	void hover(sf::RenderWindow&);
	sf::RectangleShape& getMenuBack();
};

