#include "StreamBuffer.h"

StreamBuffer::StreamBuffer()
{
}

StreamBuffer::StreamBuffer(std::string name)
{
	this->name = name;
	update();

}

std::vector<ListElement>& StreamBuffer::getStreamBufferList()
{
	return list;
}

void StreamBuffer::update()
{
	while (!list.empty()) {
		auto el = list.cbegin();
		list.erase(el);
	}

	stream = std::fstream(name, std::ios::binary | std::ios::in);

	ListElement el;

	while (stream.read((char*)&el, sizeof(ListElement))) {
		list.push_back(el);
	}
	stream.close();


}
void StreamBuffer::add(std::string title, std::string description) {

	ListElement el(title, description);

	stream = std::fstream(name, std::ios::binary | std::ios::out);
	for (int i = 0; i < list.size(); i++) {

		stream.write((char*)&list[i], sizeof(ListElement));

	}
	stream.write((char*)&el, sizeof(ListElement));
	stream.close();

	update();
}
void StreamBuffer::sortByTitle() {

	for (int i = 0; i < list.size()-1; i++) {
		for(int k = i+1 ; k < list.size(); k++)
		if (list[i].getTitle() > list[k].getTitle()){
			ListElement temp = list[k];
			list[k] = list[i];
			list[i] = temp;

		}

	}
}
void StreamBuffer::deleteEl(int index){


	stream = std::fstream(name, std::ios::binary | std::ios::out);
	for (int i = 0; i < list.size(); i++) {

		if (!(index == i)) {

			stream.write((char*)&list[i], sizeof(ListElement));

		}

	}
	stream.close();
	update();
}
void StreamBuffer::Search(std::string substr) {

	while (!list.empty()) {
		auto el = list.cbegin();
		list.erase(el);
	}

	stream = std::fstream(name, std::ios::binary | std::ios::in);

	ListElement el;

	while (stream.read((char*)&el, sizeof(ListElement))) {
		if(substringIncluded(el.getTitle(), substr)) list.push_back(el);
	}
	stream.close();


}