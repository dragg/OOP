#include "Date.h"

//----------------------------------------Конструкторы и деструктор -------------------------------
Date::Date(void)
{
	_day = DAY_MIN;
	_month = MONTH_MIN;
	_year = YEAR_MIN;
}
Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}
Date::~Date(void)
{
}
//--------------------------------------------------------------------------------------------------


//----------------------------------- Все для проверки правильности даты --------------------------
bool Date::IsValidDate(int day, int mount, int year) const
{
	return IsValidYear(year) && IsValidMonth(mount) && IsValidDay(day, mount, year);
}
bool Date::IsValidYear(int year) const
{
	return year >= YEAR_MIN && year <= YEAR_MAX;
}
bool Date::IsValidMonth(int month) const
{
	return month >= MONTH_MIN && month <= MONTH_MAX;
}
bool Date::IsValidDay(int day, int month, int year) const
{
	return day >= DAY_MIN && day <= GetLengthOfMonth(month, year);
}
int Date::GetLengthOfMonth(int month, int year) const
{
	int length = 31;
	switch (month)
	{
	case 2:
		length = IsLeapYear(year) ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		length = 30;
		break;
	}

	return length;
}
bool Date::IsLeapYear(int year) const
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
//--------------------------------------------------------------------------------------------------


//-------------------------------------- Доступ к значениям полей класса ---------------------------
int Date::GetDay() const
{
	return _day;
}
int Date::GetMonth()const
{
	return _month;
}
int Date::GetYear() const
{
	return _year;
}
//--------------------------------------------------------------------------------------------------

//------------------------------------------Операции с датой ---------------------------------------
void Date::AddDay(int lengthOfMonth)
{
	if(_day < (lengthOfMonth != 0 ? lengthOfMonth : this->GetLengthOfMonth(_month, _year)))
	{
		++_day;
	}
	else
	{
		AddMonth();
		_day = 1;
	}
}
void Date::AddMonth()
{
	if(_month < MONTH_MAX)
	{
		++_month;
	}
	else
	{
		++_year;
		_month = 1;
	}
}

void Date::SubtractDay()
{
	if(*this)
	{
		if(_day > 1)
		{
			--_day;
		}
		else
		{
			SubtractMonth();
			_day = GetLengthOfMonth(_month, _year);
		}
	}
}
void Date::SubtractMonth()
{
	if(_month > 1)
	{
		--_month;
	}
	else
	{
		--_year;
		_month = MONTH_MAX;
	}
}
//--------------------------------------------------------------------------------------------------


//--------------------------------------------Другие функции ---------------------------------------
string Date::GetDayOfTheWeek() const
{
	string dayOfTheWeek;
	if (*this)
	{
		dayOfTheWeek = GetDayOfTheWeek(GetCountDays() % 7);
	}
	else
	{
		dayOfTheWeek = MESSAGE_ERROR;
	}
	return dayOfTheWeek;
}
string Date::GetDayOfTheWeek(int days) const
{
	string day;
	switch (days)
	{
	case 0:
		day = "Sunday";
		break;
	case 1:
		day = "Monday";
		break;
	case 2:
		day = "Tuesday";
		break;
	case 3:
		day = "Wednesday";
		break;
	case 4:
		day = "Thursday";
		break;
	case 5:
		day = "Friday";
		break;
	case 6:
		day = "Saturday";
		break;
	}
	return day;
}
int Date::GetCountDays() const
{
	int days = (_year - YEAR_MIN) * 365 + GetCountLeapYear() - (IsLeapYear(_year) ? 1 : 0);

	for (int i = 1; i < _month; i++)
	{
		days += GetLengthOfMonth(i, _year);
	}

	days += _day;

	return days;
}
int Date::GetCountLeapYear() const
{
	int different = _year - YEAR_MIN;
	int count = (int)(different / 4) - (int)(different / 100) + (int)(_year / 400 - YEAR_MIN / 400);
	return count;
}
//--------------------------------------------------------------------------------------------------


//-----------------------------------------Перегруженные операции ---------------------------------
Date::operator bool() const
{
	return IsValidDate(_day, _month, _year);
}
Date& Date::operator+= (int n)
{
	if(*this)
	{
		int length = GetLengthOfMonth(_month, _year);
		for (int i = 0; i < n; i++)
		{
			AddDay(length);
		}
	}
	return *this;
}
Date& Date::operator-= (int n)
{
	if(*this)
	{
		for (int i = 0; i < n; i++)
		{
			SubtractDay();
		}
	}
	return *this;
}
//--------------------------------------------------------------------------------------------------


//----------------------------Перегрузка операторов ввода/вывода ----------------------------------
istream& operator>>(istream& cin, Date& date)
{
	return cin >> date._day >> date._month >> date._year;
}
ostream& operator<<(ostream& cout, const Date& date)
{
	if(date)
	{
		cout << date._day << "." << date._month << "." << date._year ;
	}
	else
	{
		cout << MESSAGE_ERROR;
	}

	return cout;
}
//------------------------------------------------------------------------------------------------