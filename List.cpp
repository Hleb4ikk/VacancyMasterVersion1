#include "List.h"

List::List(std::string name, sf::Font& font, float width, float height, float PositionX, float PositionY)
{
	this->name = name;
	this->PositionX = PositionX;
	this->PositionY = PositionY;
	update(font, width, height);
}

void List::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < list.size(); i++) {
		window.draw(list[i].getContainerS());
		window.draw(list[i].getTitleS());
	}
}

void List::ChangePosition(float value) {
	PositionY = PositionY + value;
	for (int i = 0; i < list.size(); i++) {

		list[i].setPositionY(value);

	}

}

std::vector<ListElement>& List::getList()
{

	return list;

}
void List::add(sf::Font& font, std::string title, std::string description, float width, float height) {
	ListElement el(sf::Color(147, 147, 147), sf::Color(0, 0, 0), font, width / 1.08, height / 10, this->PositionX, this->PositionY + height / 10 * list.size() + height / 35 * list.size());

	el.setTitle(title);
	el.setDescription(description);

	stream = std::fstream(name, std::ios::app);
	stream.write((char*)&el, sizeof(ListElement));

}

void List::deleteEl(int index, sf::Font& font, float width, float height)
{	

	std::string s;
	std::string data;
	stream = std::fstream(name, std::ios::in);

	int i = 0;
	while (getline(stream, s)) {

		if (i != index) {

			data = data + s + '\n';

		}
		s = "";
		i++;
	}
	stream.close();

	stream = std::fstream(name, std::ios::out);
	stream << data;
	stream.close();
	update(font, width, height);


}


void List::update(sf::Font& font, float width, float height) {

	while (!list.empty()) {
		auto iterator = list.cbegin();
		list.erase(iterator);

	}

	stream = std::fstream(name);
	ListElement el;
	int i = 0;
	while (stream.read((char*)&el, sizeof(ListElement))) {

		list.push_back(ListElement(sf::Color(147, 147, 147), sf::Color(0, 0, 0), font, width / 1.08, height / 10, this->PositionX, this->PositionY + height / 10 * i + height / 35 * i));
		i++;
	}

	stream.close();

}


