#include <iostream>
#include "MyBase.h"

using namespace std;

int main()
{
	MyBase mb;
	mb.In(2, cin);
	mb.Out(cout);
	mb.InFile();
	mb.Out(cout);
	mb.Sort();
	mb.Out();
	return 0;
}