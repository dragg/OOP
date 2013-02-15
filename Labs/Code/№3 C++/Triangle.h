#pragma once
#include "shape.h"
#include "Line.h"
class Triangle :
	public Shape
{
private:
	void Init();
	double GetPerimeter() const;//вычисление периметра
public:
	double GetArea();
	Point GetCenterOfGravity();
	double GetInscribedRadius();
	double GetCircumscribedRadius();

	Triangle(void);
	Triangle(Point p1, Point p2, Point p3);
	~Triangle(void);
};

