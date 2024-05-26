#pragma once

#include <SFML/Graphics.hpp>
#include "ListElement.h"
#include "TextField.h"

class ListGraphicalElement
{
private:
	sf::ConvexShape container;
	sf::Text title;
	sf::Text description;

	float PositionX;
	float PositionY;

	float height;
	float width;
public:
	ListGraphicalElement();
	ListGraphicalElement(sf::Color, sf::Color, sf::Font&, float, float, float, float);
	void setTitle(std::string);
	void setDescription(std::string);
	sf::Text& getTitleS();
	sf::Text& getDescriptionS();
	sf::ConvexShape getContainerS();
	void setPositionY(float);
	bool isMouseOver(sf::RenderWindow&);
	void setBColor(sf::Color);
};

