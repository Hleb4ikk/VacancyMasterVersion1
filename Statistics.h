#pragma once
#include "StreamBuffer.h"
class Statistics
{

private: 
	int VacanciesCapacity = 0;
	int AppliesCapacity = 0;
	int EmployeesCapacity = 0;

	int JavaCapacityOfVacancies = 0;
	int CPPCapacityOfVacancies = 0;
	int PythonCapacityOfVacancies = 0;
	int CSCapacityOfVacancies = 0;
	int GOCapacityOfVacancies = 0;
	int OtherCapacityOfVacancies = 0;

	float JavaPercentOfVacancies = 0;
	float CPPPercentOfVacancies = 0;
	float PythonPercentOfVacancies = 0;
	float CSPercentOfVacancies = 0;
	float GOPercentOfVacancies = 0;
	float OtherPercentOfVacancies = 0;

	void countVacanciesCapacity(StreamBuffer&);

	void countJavaCapacityOfVacancies(StreamBuffer&);
	void countCPPCapacityOfVacancies(StreamBuffer&);
	void countPythonCapacityOfVacancies(StreamBuffer&);
	void countCSCapacityOfVacancies(StreamBuffer&);
	void countGOCapacityOfVacancies(StreamBuffer&);
	void countOtherCapacityOfVacancies();

	void countJavaPercentOfVacancies();
	void countCPPPercentOfVacancies();
	void countPythonPercentOfVacancies();
	void countCSPercentOfVacancies();
	void countGOPercentOfVacancies();
	void countOtherPercentOfVacancies();

public:

	void countAppliesCapacity(StreamBuffer&);
	void countEmployeesCapacity(StreamBuffer&);



	void countAllWithVacancies(StreamBuffer&);

	int getVacanciesCapacity();
	int getAppliesCapacity();
	int getEmployeesCapacity();

	int getJavaCapacityOfVacancies();
	int getCPPCapacityOfVacancies();
	int getPythonCapacityOfVacancies();
	int getCSCapacityOfVacancies();
	int getGOCapacityOfVacancies();
	int getOtherCapacityOfVacancies();

	float getJavaPercentOfVacancies();
	float getCPPPercentOfVacancies();
	float getPythonPercentOfVacancies();
	float getCSPercentOfVacancies();
	float getGOPercentOfVacancies();
	float getOtherPercentOfVacancies();
};