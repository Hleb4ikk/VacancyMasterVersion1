#include "Menu.h"

Menu::Menu(sf::Font& font, float width, float height, float PositionX, float PositionY, float spacing)
{
	menuBack.setSize(sf::Vector2f(width, height/6.2));
	menuBack.setFillColor(sf::Color(204, 204, 204));
	this->width = width;
	this->height = height;
	this->PositionX = PositionX;
	this->PositionY = PositionY;
	this->spacing = spacing;

	buttons.push_back(Button("Vacancies List", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height/10));
	buttons.push_back(Button("Applies", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	buttons.push_back(Button("Statistics", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	buttons.push_back(Button("Employees Vac.", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	buttons.push_back(Button("Settings", font, sf::Color(147, 147, 147), sf::Color(0, 0, 0), width / 6, height / 10));
	
	for (int i = 0; i < buttons.size(); i++) {

		buttons[i].setPosition(this->PositionX + i * buttons[i].getWidth() + spacing * i, this->PositionY);

	}
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(menuBack);
	for (int i = 0; i < buttons.size(); i++) {

		buttons[i].drawButton(window);

	}
}

std::vector<Button>& Menu::getButtons()
{
	return buttons;
}

void Menu::hover(sf::RenderWindow& window) {

	for (int i = 0; i < getButtons().size(); i++) {

		if (getButtons()[i].isMouseOver(window)) {

			getButtons()[i].setBColor(sf::Color(130, 130, 130));

		}
		else {

			getButtons()[i].setBColor(sf::Color(147, 147, 147));

		}
	}

}
sf::RectangleShape& Menu::getMenuBack()
{
	return menuBack;
}

