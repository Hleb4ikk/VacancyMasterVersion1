#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "ListElement.h"
class List
{
private:
	std::string name;
	std::fstream stream;
	std::vector<ListElement> list;
	float PositionX;
	float PositionY;
public:
	List(std::string, sf::Font&, float, float, float, float);
	void draw(sf::RenderWindow& window);
	void ChangePosition(float);
	std::vector<ListElement>& getList();
	void deleteEl(int,sf::Font&, float, float);
	void update(sf::Font&, float, float);
};

