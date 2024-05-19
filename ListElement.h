#pragma once

#include <SFML/Graphics.hpp>
#include "TextField.h"
class ListElement
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
	ListElement();
	ListElement(sf::Color, sf::Color, sf::Font&, float, float, float, float);
	void setTitle(std::string);
	void setDescription(std::string);

	std::string getTitle();
	std::string getDescription();
	sf::Text& getTitleS();
	sf::Text getDescriptionS();
	sf::ConvexShape getContainerS();
	void setPositionY(float);
	bool isMouseOver(sf::RenderWindow&);
	void setBColor(sf::Color);
};

