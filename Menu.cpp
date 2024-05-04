#include "Menu.h"

Menu::Menu(sf::Font& font, float width, float height, float PositionX, float PositionY, float spacing)
{

	this->width = width;
	this->height = height;
	this->PositionX = PositionX;
	this->PositionY = PositionY;
	this->spacing = spacing;

	buttons.push_back(Button("Vacancies List", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height/10));
	buttons.push_back(Button("Applies", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	buttons.push_back(Button("Statistics", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	buttons.push_back(Button("Employees", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	buttons.push_back(Button("Settings", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	
	for (int i = 0; i < buttons.size(); i++) {

		buttons[i].setPosition(this->PositionX + i * buttons[i].getWidth() + spacing * i, this->PositionY);

	}
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < buttons.size(); i++) {

		buttons[i].drawButton(window);

	}
}

std::vector<Button>& Menu::getButtons()
{
	return buttons;
}


