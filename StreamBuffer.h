#pragma once

#include <fstream>
#include <vector>
#include "ListElement.h"

class StreamBuffer
{
private:
	std::string name;
	std::fstream stream;
	std::vector<ListElement> list;

public:
	StreamBuffer();
	StreamBuffer(std::string);
	std::vector<ListElement>& getStreamBufferList();
	void update();
	void add(std::string, std::string);
	void sortByTitle();
	void deleteEl(int);
	void Search(std::string);

	bool substringIncluded(std::string str, std::string substr) {
		int counter = substr.size();
		if (!(substr.size() > str.size())) {
			for (int i = 0; i < str.size() - substr.size()+1; i++) {

				for (int k = 0; k < substr.size(); k++) {

					if (str[i + k] == substr[k]) {

						counter--;

					}
					else {

						break;

					}

				}
				if (counter == 0) return 1;
				else counter = substr.size();
			}
		}
		if (counter != 0) return 0;
	}
};

