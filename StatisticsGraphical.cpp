#include "StatisticsGraphical.h"

StatisticsGraphical::StatisticsGraphical(sf::Font& font, sf::Color color, Statistics& statistics, float size, float posX, float posY) {

	for (int i = 0; i < N; i++) {

		stat[i].setCharacterSize(size);
		stat[i].setFont(font);
		stat[i].setFillColor(color);

	}
	stat[0].setString("Capacity of vacancies: ");
	stat[1].setString("Capacity of applies: ");
	stat[2].setString("Capacity of employees: ");

	stat[3].setString("Java Vacancies: ");
	stat[4].setString("C++ Vacancies: ");
	stat[5].setString("Python Vacancies: ");
	stat[6].setString("C# Vacancies: ");
	stat[7].setString("GO Vacancies: ");
	stat[8].setString("Other Vacancies: ");
	update(statistics);
	for (int i = 0; i < N; i++) {

		stat[i].setPosition(posX, posY + stat[i].getGlobalBounds().height*i + size*i);

	}
}
void StatisticsGraphical::update(Statistics& statistics) {

	stat[0].setString("Capacity of vacancies: " + std::to_string(statistics.getVacanciesCapacity()));
	stat[1].setString("Capacity of applies: " + std::to_string(statistics.getAppliesCapacity()));
	stat[2].setString("Capacity of employees: " + std::to_string(statistics.getEmployeesCapacity()));

	stat[3].setString("Java Vacancies: " + std::to_string(statistics.getJavaPercentOfVacancies()) + "% (" + std::to_string(statistics.getJavaCapacityOfVacancies()) + ")");
	stat[4].setString("C++ Vacancies: " + std::to_string(statistics.getCPPPercentOfVacancies()) + "% (" + std::to_string(statistics.getCPPCapacityOfVacancies()) + ")");
	stat[5].setString("Python Vacancies: " + std::to_string(statistics.getPythonPercentOfVacancies()) + "% (" + std::to_string(statistics.getPythonCapacityOfVacancies()) + ")");
	stat[6].setString("C# Vacancies: " + std::to_string(statistics.getCSPercentOfVacancies()) + "% (" + std::to_string(statistics.getCSCapacityOfVacancies()) + ")");
	stat[7].setString("GO Vacancies: " + std::to_string(statistics.getGOPercentOfVacancies()) + "% (" + std::to_string(statistics.getGOCapacityOfVacancies()) + ")");
	stat[8].setString("Other Vacancies: " + std::to_string(statistics.getOtherPercentOfVacancies()) + "% (" + std::to_string(statistics.getOtherCapacityOfVacancies()) + ")");

}

void StatisticsGraphical::DrawTo(sf::RenderWindow& window)
{
	for(int i = 0; i < N; i++) window.draw(stat[i]);

}

