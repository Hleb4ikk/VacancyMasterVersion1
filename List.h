#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "StreamBuffer.h"
#include "ListGraphicalElement.h"

class List
{
private:
	std::vector<ListGraphicalElement> list;
	float PositionX;
	float PositionY;
public:
	List(StreamBuffer&, sf::Font&, float, float, float, float);
	void draw(sf::RenderWindow& window);
	void ChangePosition(float);
	float getPosition();
	std::vector<ListGraphicalElement>& getList();
	void update(StreamBuffer&, sf::Font&, float, float);
};

