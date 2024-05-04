#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Menu.h"

class MainWindow
{
private:
	sf::RenderWindow window;
	float width;
	float height;
public:
	MainWindow();
	void run(/*Button* button, ButtonList, ButtonList, ButtonList */);

};

