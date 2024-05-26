#pragma once

#include <string>

class ListElement
{
private:
	char title[200];
	char description[200];
public:
	ListElement();
	ListElement(std::string, std::string);

	std::string getTitle();
	std::string getDescription();

	void setTitle(std::string);
	void setDescription(std::string);
};

