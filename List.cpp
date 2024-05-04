#include "List.h"

List::List(std::string name, sf::Font font)
{

	stream = std::fstream(name);
	
	std::string s;
	bool infoType;
	std::string keyword = "";
	ListElement el(sf::Color(147, 147, 147), sf::Color(0, 0, 0), font, 200, 50, 300, 300);

	while (getline(stream, s));

	for (int i = 0; i < s.size(); i++) {

		keyword += s[i];

	}

	stream.close();
	
}
