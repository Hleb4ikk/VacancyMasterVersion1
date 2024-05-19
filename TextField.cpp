#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "TextField.h"
TextField::TextField(){}
TextField::TextField(int size, sf::Color color, sf::Color BColor, bool sel, float width, float height) {

	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;

	// Check if the textbox is selected upon creation and display it accordingly:
	if (isSelected)
		textbox.setString("_");
	else
		textbox.setString("");

	background.setFillColor(BColor);
	background.setSize(sf::Vector2f(width, height));

}
bool TextField::isSelect() { return isSelected; }
void TextField::setText(std::string stroke)
{
	
	text.str(stroke);
	textbox.setString(text.str() + "_");

}

void TextField::setFont(sf::Font& fonts) {
	textbox.setFont(fonts);
}
void TextField::setSize(sf::Vector2f point) {

	background.setSize(point);

}

void TextField::setPosition(sf::Vector2f point) {
	textbox.setPosition(point.x - background.getGlobalBounds().width / 2.1, point.y + background.getGlobalBounds().height / 3.1);
	background.setPosition(point.x - background.getGlobalBounds().width / 2, point.y);
}

// Set char limits:
void TextField::setLimit(bool ToF) {
	hasLimit = ToF;
}

void TextField::setLimit(bool ToF, int limit) {
	hasLimit = ToF;
	this->limit = limit - 1;
}

// Change selected state:
void TextField::setSelected(bool sel) {
	isSelected = sel;

	// If not selected, remove the '_' at the end:
	if (!sel) {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) {
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string TextField::getText() {
	return text.str();
}

void TextField::drawTo(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(textbox);
}

// Function for event loop:
void TextField::typedOn(sf::Event input) {
	if (isSelected) {
		int charTyped = input.text.unicode;

		// Only allow normal inputs:
		if (charTyped < 128) {
			if (hasLimit) {
				// If there's a limit, don't go over it:
				if (text.str().length() <= limit) {
					inputLogic(charTyped);
				}
				// But allow for char deletions:
				else if (text.str().length() > limit && charTyped == DELETE_KEY) {
					deleteLastChar();
				}

			}
			// If no limit exists, just run the function:
			else {
				inputLogic(charTyped);
			}
		}
	}
}
