#pragma once
#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

class Operation
{
public:
	void Compare(Shape* s1, Shape* s2) const;//сравнение по площади
	void IsInclude(Shape* s1, Shape* s2) const;//включение одной из фигур другую
	void IsIntersect(Shape* s1, Shape* s2) const;//пересечение двух фигур
	Operation(void);
	~Operation(void);
};

