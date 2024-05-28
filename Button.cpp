#include "Button.h"

Button::Button(std::string title, sf::Font& font, sf::Color c, sf::Color textColor, float width, float height, float PositionX, float PositionY) { //конструктор для кнопок +-

	this->title.setFont(font);
	this->title.setString(title);
	this->title.setCharacterSize(width/1.8);
	this->title.setFillColor(textColor);

	this->width = width;
	this->height = height;

	container.setFillColor(c);

	float R = this->height/2;

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
	this->title.setPosition(this->PositionX + (this->container.getGlobalBounds().width - this->container.getGlobalBounds().height) / 2 - this->title.getGlobalBounds().width / 1.6, this->PositionY - this->height / 2.9);
}

Button::Button(std::string title, sf::Font& font, sf::Color c, sf::Color textColor, float width, float height) //конструктор для меню
{
	this->title.setFont(font);
	this->title.setString(title);
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
	this->title.setPosition(this->PositionX + (this->width - this->height) / 2 - this->title.getGlobalBounds().width / 2, this->PositionY - this->height / 4);
}

float Button::getWidth()
{
	return width;
}

void Button::setBColor(sf::Color c) {
	container.setFillColor(c);
}

bool Button::isMouseOver(sf::RenderWindow& window) {

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
void Button::setPosition(float PositionX, float PositionY)
{

	container.setPosition(PositionX, PositionY);
	title.setPosition(PositionX + (width - this->height) / 2 - title.getGlobalBounds().width / 2, PositionY - height / 5);

}
void Button::drawButton(sf::RenderWindow& window)
{
	
	window.draw(container);
	window.draw(title);

}

sf::Text& Button::getTitle()
{
	return title;
}
void Button::hover(sf::RenderWindow& window) {

	if (isMouseOver(window)) {

		setBColor(sf::Color(130, 130, 130));

	}
	else {

		setBColor(sf::Color(147, 147, 147));

	}

}
