#include <iostream>
#include "Triangle.h"
#include "Square.h"
#include "Operation.h"
#include "Point.h"
#include "Line.h"
using namespace std;

int main()
{
	Shape *shape1, *shape2;
	shape1 = new Triangle(Point(1, 1), Point(1, 3), Point(2, 3));
	shape2 = new Square(Point(0, 0), Point(0, 4), Point(4, 4), Point(4, 0));
	Operation oper;
	oper.Compare(shape1, shape2);
	oper.IsIntersect(shape2, shape1);
	oper.IsInclude(shape2, shape1);
	return 0;
}