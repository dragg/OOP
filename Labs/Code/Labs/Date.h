#pragma once
#include <string>

using namespace std;

const string MESSAGE_ERROR = "Incorrect date!";

class Date
{
private:
	static enum
	{
		DAY_MIN = 1,
		MONTH_MIN = 1,
		MONTH_MAX = 12,
		YEAR_MIN = 1900,
		YEAR_MAX = 2400,
	};
	int _day;
	int _month;
	int _year;

	bool IsValidDate(int day, int month, int year) const;
	bool IsValidYear(int year) const;
	bool IsValidMonth(int month) const;
	bool IsValidDay(int day, int month, int year) const;
	int GetLengthOfMonth(int month, int year) const;
	bool IsLeapYear(int year) const;

	void AddDay(int lengthOfMonth = 0);
	void AddMonth();
	void SubtractDay();
	void SubtractMonth();

	int GetCountLeapYear() const;
	int GetCountDays() const;
	string GetDayOfTheWeek(int days) const;

public:
	Date(void);
	Date(int day, int month, int year);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	
	string GetDayOfTheWeek() const;
	//Перегруженные операции +=, -=(для сложения или вычитания дней из даты)
	//и приведение к типу bool(для проверки действительности даты)
	operator bool() const;
	Date& operator+= (int n);
	Date& operator-= (int n);

	friend istream& operator>>(istream& cin, Date& date);
	friend ostream& operator<<(ostream& cout, const Date& date);

	~Date(void);
};