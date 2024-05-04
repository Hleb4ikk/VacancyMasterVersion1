#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

class Button
{
private:
	sf::ConvexShape container;
	sf::Text title;

	float PositionX;
	float PositionY;

	float height;
	float width;
	
public:

	Button(std::string, sf::Font&, sf::Color, sf::Color, float, float, float, float);
	Button(std::string, sf::Font&, sf::Color, sf::Color, float, float);
	float getWidth();
	void setBColor(sf::Color);
	bool isMouseOver(sf::RenderWindow&);
	void setPosition(float, float);
	void drawButton(sf::RenderWindow&);
};

