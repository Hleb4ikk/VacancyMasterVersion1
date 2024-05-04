#pragma once
#include <fstream>
#include <vector>
#include "ListElement.h"
class List
{
private:
	std::fstream stream;
	std::vector<ListElement> list;
public:
	List(std::string, sf::Font);

};

