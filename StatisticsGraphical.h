#pragma once
#include <SFML/Graphics.hpp>
#include "Statistics.h"
#include "StreamBuffer.h"
class StatisticsGraphical
{
private:
	int N = 9;
	sf::Text* stat = new sf::Text[N];
	
public:
	StatisticsGraphical(sf::Font&, sf::Color, Statistics&, float, float, float);
	~StatisticsGraphical(){

		delete[] stat;

	}
	void update(Statistics&);
	void DrawTo(sf::RenderWindow&);
};

