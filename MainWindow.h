#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Menu.h"
#include "List.h"
#include "TextField.h"
#include "StreamBuffer.h"
#include "Statistics.h"
#include "StatisticsGraphical.h"

class MainWindow
{
private:
	sf::RenderWindow window;
	float width;
	float height;
public:
	MainWindow();
	void run();
	bool isInListArea(sf::RectangleShape&, sf::RectangleShape&);
};

