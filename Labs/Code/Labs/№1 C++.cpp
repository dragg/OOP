#include <iostream>
#include "Date.h"

using namespace std;


int main()
{
	Date date(8, 2, 2013);
	cout << date.GetDayOfTheWeek() << endl;//Friday
	cout << date << endl;//8.2.2013

	date += 43;
	cout << date.GetDayOfTheWeek() << endl;//Saturday
	cout << date << endl;//23.3.2013

	date -= 23;
	cout << date.GetDayOfTheWeek() << endl;//Thursday
	cout << date << endl;//28.2.2013

	return 0;
}

