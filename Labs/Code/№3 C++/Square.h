#pragma once
#include "shape.h"
#include "Line.h"
#include <algorithm>
class Square :
	public Shape
{
private:
	void Init();
	double GetA() const;//получить длину стороны квадрата
public:
	double GetArea();
	Point GetCenterOfGravity();
	double GetInscribedRadius();
	double GetCircumscribedRadius();
	
	operator bool() const;
	Square(Point A, Point B, Point C, Point D);
	Square(void);
	~Square(void);
};

