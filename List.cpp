#include "List.h"

List::List(StreamBuffer& buffer, sf::Font& font, float width, float height, float PositionX, float PositionY)
{	
	this->PositionX = PositionX;
	this->PositionY = PositionY;
	
	update(buffer, font, width, height);

}

void List::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < list.size(); i++) {
		window.draw(list[i].getContainerS());
		window.draw(list[i].getTitleS());
		window.draw(list[i].getDescriptionS());
	}
}

void List::ChangePosition(float value) {
	PositionY = PositionY + value;

	for (int i = 0; i < list.size(); i++) {

		list[i].setPositionY(value);

	}

}
float List::getPosition() {

	return PositionY;

}
std::vector<ListGraphicalElement>& List::getList()
{

	return list;

}
void List::update(StreamBuffer& buffer, sf::Font& font, float width, float height) {

	while (!list.empty()) {
		auto el = list.cbegin();
		list.erase(el);
	}

	for (int i = 0; i < buffer.getStreamBufferList().size(); i++) {
		ListGraphicalElement el(sf::Color(147, 147, 147), sf::Color(0, 0, 0), font, width / 1.08, height / 10, PositionX, PositionY + height / 10 * list.size() + height / 35 * list.size());
		el.setTitle(buffer.getStreamBufferList()[i].getTitle());
		el.setDescription(buffer.getStreamBufferList()[i].getDescription());
		list.push_back(el);

	}

}
void List::hover(sf::RenderWindow& window) {

	for (int i = 0; i < getList().size(); i++) {

		if (getList()[i].isMouseOver(window)) {

			getList()[i].setBColor(sf::Color(130, 130, 130));

		}
		else {

			getList()[i].setBColor(sf::Color(147, 147, 147));

		}

	}

}



