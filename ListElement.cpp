#include "ListElement.h"

ListElement::ListElement(sf::Color c, sf::Color textColor, sf::Font& font, float width, float height, float PositionX, float PositionY)
{
	this->title.setFont(font);
	this->title.setCharacterSize(width / 10);
	this->title.setFillColor(textColor);

	this->width = width;
	this->height = height;

	container.setFillColor(c);

	float R = this->height / 2;

	container.setPointCount(4 * R + 2);

	int counter = 0;

	for (float y = -R; y <= R; y += 1) {

		container.setPoint(counter, sf::Vector2f(-sqrt(R * R - y * y), y));
		counter++;

	}
	for (float y = R; y >= -R; y -= 1) {

		container.setPoint(counter, sf::Vector2f(sqrt(R * R - y * y) + this->width - this->height, y));
		counter++;

	}

	this->PositionX = 0;
	this->PositionY = 0;


	this->container.setPosition(this->PositionX, this->PositionY);



}

void ListElement::setTitle(std::string s)
{

	title.setString(s);
	title.setPosition(PositionX + (width - height) / 2 - title.getGlobalBounds().width / 2, PositionY - height / 4);
}

void ListElement::setDescription(std::string s)
{

	title.setString(s);
	title.setPosition(PositionX + (width - height) / 2 - title.getGlobalBounds().width / 2, PositionY - height / 4);
}
std::string ListElement::getTitle() {

	return title.getString();

}
std::string ListElement::getDescription() {

	return description.getString();

}
