#include "Statistics.h"

void Statistics::countVacanciesCapacity(StreamBuffer& stream)
{
	VacanciesCapacity = stream.getStreamBufferList().size();
}

void Statistics::countAppliesCapacity(StreamBuffer& stream)
{
	AppliesCapacity = stream.getStreamBufferList().size();
}

void Statistics::countEmployeesCapacity(StreamBuffer& stream)
{
	EmployeesCapacity = stream.getStreamBufferList().size();
}

void Statistics::countJavaCapacityOfVacancies(StreamBuffer& stream)
{
	stream.Search("java");
	JavaCapacityOfVacancies = stream.getStreamBufferList().size();
	stream.update();
	stream.Search("Java");
	JavaCapacityOfVacancies += stream.getStreamBufferList().size();
	stream.update();
}

void Statistics::countCPPCapacityOfVacancies(StreamBuffer& stream)
{
	stream.Search("C++");
	CPPCapacityOfVacancies = stream.getStreamBufferList().size();
	stream.update();
	stream.Search("c++");
	CPPCapacityOfVacancies += stream.getStreamBufferList().size();
	stream.update();
}

void Statistics::countPythonCapacityOfVacancies(StreamBuffer& stream)
{
	stream.Search("python");
	PythonCapacityOfVacancies = stream.getStreamBufferList().size();
	stream.update();
	stream.Search("Python");
	PythonCapacityOfVacancies += stream.getStreamBufferList().size();
	stream.update();
}

void Statistics::countCSCapacityOfVacancies(StreamBuffer& stream)
{
	stream.Search("C#");
	CSCapacityOfVacancies = stream.getStreamBufferList().size();
	stream.update();
	stream.Search("c#");
	CSCapacityOfVacancies += stream.getStreamBufferList().size();
	stream.update();
}

void Statistics::countGOCapacityOfVacancies(StreamBuffer& stream)
{
	stream.Search("Go");
	GOCapacityOfVacancies = stream.getStreamBufferList().size();
	stream.update();
	stream.Search("go");
	GOCapacityOfVacancies += stream.getStreamBufferList().size();
	stream.update();
}

void Statistics::countOtherCapacityOfVacancies()
{
	OtherCapacityOfVacancies = VacanciesCapacity - JavaCapacityOfVacancies - CPPCapacityOfVacancies -
							   PythonCapacityOfVacancies - CSCapacityOfVacancies - GOCapacityOfVacancies;
}

void Statistics::countJavaPercentOfVacancies()
{

	JavaPercentOfVacancies = ((float)JavaCapacityOfVacancies / (float)VacanciesCapacity) * 100;

}

void Statistics::countCPPPercentOfVacancies()
{
	CPPPercentOfVacancies = ((float)CPPCapacityOfVacancies / (float)VacanciesCapacity) * 100;
}

void Statistics::countPythonPercentOfVacancies()
{

	PythonPercentOfVacancies = ((float)PythonCapacityOfVacancies / (float)VacanciesCapacity) * 100;

}

void Statistics::countCSPercentOfVacancies()
{

	CSPercentOfVacancies = ((float)CSCapacityOfVacancies / (float)VacanciesCapacity) * 100;

}

void Statistics::countGOPercentOfVacancies()
{
	GOPercentOfVacancies = ((float)GOCapacityOfVacancies / (float)VacanciesCapacity) * 100;
}

void Statistics::countOtherPercentOfVacancies()
{
	OtherPercentOfVacancies = ((float)OtherCapacityOfVacancies / (float)VacanciesCapacity) * 100;
}

void Statistics::countAllWithVacancies(StreamBuffer& stream)
{
	countVacanciesCapacity(stream);

	countJavaCapacityOfVacancies(stream);
	countCPPCapacityOfVacancies(stream);
	countPythonCapacityOfVacancies(stream);
	countCSCapacityOfVacancies(stream);
	countGOCapacityOfVacancies(stream);
	countOtherCapacityOfVacancies();

	countJavaPercentOfVacancies();
	countCPPPercentOfVacancies();
	countPythonPercentOfVacancies();
	countCSPercentOfVacancies();
	countGOPercentOfVacancies();
	countOtherPercentOfVacancies();
}

int Statistics::getVacanciesCapacity()
{
	return VacanciesCapacity;
}

int Statistics::getAppliesCapacity()
{
	return AppliesCapacity;
}

int Statistics::getEmployeesCapacity()
{
	return EmployeesCapacity;
}

int Statistics::getJavaCapacityOfVacancies()
{
	return JavaCapacityOfVacancies;
}

int Statistics::getCPPCapacityOfVacancies()
{
	return CPPCapacityOfVacancies;
}

int Statistics::getPythonCapacityOfVacancies()
{
	return PythonCapacityOfVacancies;
}

int Statistics::getCSCapacityOfVacancies()
{
	return CSCapacityOfVacancies;
}

int Statistics::getGOCapacityOfVacancies()
{
	return GOCapacityOfVacancies;
}

int Statistics::getOtherCapacityOfVacancies()
{
	return OtherCapacityOfVacancies;
}

float Statistics::getJavaPercentOfVacancies()
{
	return JavaPercentOfVacancies;
}

float Statistics::getCPPPercentOfVacancies()
{
	return CPPPercentOfVacancies;
}

float Statistics::getPythonPercentOfVacancies()
{
	return PythonPercentOfVacancies;
}

float Statistics::getCSPercentOfVacancies()
{
	return CSPercentOfVacancies;
}

float Statistics::getGOPercentOfVacancies()
{
	return GOPercentOfVacancies;
}

float Statistics::getOtherPercentOfVacancies()
{
	return OtherPercentOfVacancies;
}
