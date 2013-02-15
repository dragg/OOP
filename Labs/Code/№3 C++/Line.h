#include "Point.h"
#include <algorithm>

#pragma once
class Line
{
private:
	Point A;
	Point B;
	double Get_k();//получение соответственного коэффициэнта уравнения прямой y=kx+b
	double Get_b();//получение соответственного коэффициэнта уравнения прямой y=kx+b
public:
	double GetLength();//получение длины отрезка
	Point GetCentralPoint();//получение точки центра отрезка
	Point GetCrossoverPoint(Line line);//получение точки пересечения для 2х отрезков
	Line(Point A_, Point B_);
	~Line(void);
};

