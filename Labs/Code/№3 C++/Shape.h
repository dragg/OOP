#include "Point.h"

#pragma once
class Shape
{
protected:
	Point* arc;
public:
	char id;

	virtual double GetArea() = 0;//вычисление площади
	virtual Point GetCenterOfGravity() = 0;//вычисление центра тяжести
	virtual double GetInscribedRadius() = 0;//вычисление вписанной окружности
	virtual double GetCircumscribedRadius() = 0;//вычисление описанной окружности

	Shape(void);
	virtual ~Shape(void);
};

