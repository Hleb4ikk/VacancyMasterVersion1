#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextField {
public:
	TextField();
	TextField(std::string title, int size, sf::Color color, sf::Color BColor, bool sel, float width, float height);
	bool isSelect();
	void setText(std::string stroke);

	// Make sure font is passed by reference:
	void setFont(sf::Font& fonts);
	void setSize(sf::Vector2f point);
	void setPosition(sf::Vector2f point);

	// Set char limits:
	void setLimit(bool ToF);

	void setLimit(bool ToF, int limit);

	// Change selected state:
	void setSelected(bool sel);

	std::string getText();

	void drawTo(sf::RenderWindow& window);

	// Function for event loop:
	void typedOn(sf::Event input);
	bool isMouseOver(sf::RenderWindow&);
private:
	sf::Text title;
	sf::Text textbox;
	sf::RectangleShape background;

	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;

	// Delete the last character of the text:
	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str() + "_");
	}

	// Get user input:
	void inputLogic(int charTyped) {
		// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
			if (!(background.getPosition().x + background.getGlobalBounds().width <= textbox.getPosition().x + textbox.getGlobalBounds().width)) {

				text << static_cast<char>(charTyped);

			}
			textbox.setString(text.str() + "_");
		}
		// If the key is delete, then delete the char:
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
			textbox.setString(text.str() + "_");
		}
		else if (charTyped == ENTER_KEY) {

			isSelected = false;
			textbox.setString(text.str());
		}

	}
};
