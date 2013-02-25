#pragma once
#include "Hexagon.h"
#include "Octagon.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Trapeze.h"
#include "Shape.h"
#include <iostream>

class FactoryShape
{
public:

	Shape* Generator();
	Shape* Choice();

	FactoryShape(void);
	~FactoryShape(void);
};

