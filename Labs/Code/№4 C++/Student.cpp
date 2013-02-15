#include "Student.h"


Student::Student(void)
{
}

Student::~Student(void)
{
}

double Student::AverageMark()
{
	return (_progress.five * 5 + _progress.four * 4 + _progress.three * 3) / (double)(_progress.five + _progress.four + _progress.three);
}

bool Student::operator<(Student student)
{
	return _NumberOfGroup < student._NumberOfGroup;
}
istream& operator>>(istream &cin, Student &student)
{
	cin >> student._lastName >> student._name >> student._patronymic >> student._NumberOfGroup >> student._progress.five >> student._progress.four >> student._progress.three;
	try
	{
		student.Check();
	}
	catch(string error)
	{
		cout << "Input error with " << error << endl;
		cout << "Chech your data and try do this operation again!" << endl;
	}
	return cin;
}
ostream& operator<<(ostream &cout, Student &student)
{
	//return cout << student._lastName << " " << student._name << " " << student._patronymic << " " << student._NumberOfGroup << " " <<student._progress.five << " " << student._progress.four << " "<< student._progress.three;
	return cout << student._lastName << " " << student._NumberOfGroup;
}

void Student::Check()
{
	for (int i = 0; i < _lastName.length(); i++)
	{
		if(isdigit(_lastName[i]))
			throw (string)"LastName";
	}
	for (int i = 0; i < _name.length(); i++)
	{
		if(isdigit(_name[i]))
			throw (string)"Name";
	}
	for (int i = 0; i < _patronymic.length(); i++)
	{
		if(isdigit(_patronymic[i]))
			throw (string)"Patronymic";
	}
	if (_progress.five < 0 || _progress.four < 0 || _progress.three < 0)
	{
		throw (string)"Progress";
	}
}