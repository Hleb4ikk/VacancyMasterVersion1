#include "ListElement.h"

ListElement::ListElement(sf::Color c, sf::Color textColor, sf::Font& font, float width, float height, float PositionX, float PositionY)
{
	this->title.setFont(font);
	this->title.setCharacterSize(width / 60);
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

	this->PositionX = PositionX;
	this->PositionY = PositionY;


	this->container.setPosition(this->PositionX, this->PositionY);



}

void ListElement::setTitle(std::string s)
{

	title.setString(s);
	title.setPosition(PositionX , PositionY - height / 5);
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

sf::Text& ListElement::getTitleS()
{
	return title;
}

sf::Text ListElement::getDescriptionS()
{
	return description;
}

sf::ConvexShape ListElement::getContainerS()
{
	return container;
}
void ListElement::setPositionY(float value) {

	PositionY = value;
	container.setPosition(sf::Vector2f(container.getPosition().x, container.getPosition().y + value));
	title.setPosition(sf::Vector2f(title.getPosition().x, title.getPosition().y + value));
	description.setPosition(sf::Vector2f(description.getPosition().x, description.getPosition().y + value));

}
bool ListElement::isMouseOver(sf::RenderWindow& window) {

	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = container.getPosition().x - height / 2;
	float btnPosY = container.getPosition().y - height / 2;

	float btnPosWidth = btnPosX + container.getGlobalBounds().width;
	float btnPosHeight = btnPosY + container.getGlobalBounds().height;

	if (mouseX < btnPosWidth && mouseX > btnPosX && mouseY < btnPosHeight && mouseY > btnPosY) {

		return true;

	}


	return false;
}

void ListElement::setBColor(sf::Color c)
{

	container.setFillColor(c);

}


