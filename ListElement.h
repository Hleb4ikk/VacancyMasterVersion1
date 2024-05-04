#pragma once

#include <SFML/Graphics.hpp>

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
	ListElement(sf::Color, sf::Color, sf::Font&, float, float, float, float);
	void setTitle(std::string);
	void setDescription(std::string);

	std::string getTitle();
	std::string getDescription();

};

