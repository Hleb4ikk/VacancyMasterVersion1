#include "ListElement.h"
ListElement::ListElement(){}
ListElement::ListElement(std::string title, std::string description)
{
	for (int i = 0; i < title.size(); i++) this->title[i] = title[i];
	for (int i = title.size(); i < 200; i++) this->title[i] = '\0';
	for (int i = 0; i < description.size(); i++) this->description[i] = description[i];
	for (int i = description.size(); i < 200; i++) this->description[i] = '\0';
}

std::string ListElement::getTitle()
{
	return title;
}

std::string ListElement::getDescription()
{
	return description;
}

void ListElement::setTitle(std::string title)
{
	for (int i = 0; i < title.size(); i++) this->title[i] = title[i];
	for (int i = title.size(); i < 200; i++) this->title[i] = '\0';
}

void ListElement::setDescription(std::string description)
{
	for (int i = 0; i < description.size(); i++) this->description[i] = description[i];
	for (int i = description.size(); i < 200; i++) this->description[i] = '\0';
}
