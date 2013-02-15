#include "Triangle.h"
#include "Line.h"
#include <algorithm>

using namespace std;

void Triangle::Init()
{
	arc = new Point[3];
	id = 'T';
}

Triangle::Triangle(void)
{
	Init();
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	Init();
	arc[0] = p1;
	arc[1] = p2;
	arc[2] = p3;
}

Triangle::~Triangle(void)
{
	delete []arc;
}

double Triangle::GetArea()
{
	Line a (arc[0], arc[1]), b (arc[0], arc[2]), c (arc[1], arc[2]);
	double p = (a.GetLength() + b.GetLength() + c.GetLength()) / 2;
	double S = sqrt(p * (p - a.GetLength()) * (p - b.GetLength()) * (p -c.GetLength()));
	return S;
}

Point Triangle::GetCenterOfGravity()
{
	Line l1(arc[0], arc[1]);
	l1 = Line(l1.GetCentralPoint(), arc[2]);
	Line l2(arc[0], arc[2]);
	l2 = Line(l2.GetCentralPoint(), arc[1]);
	return l1.GetCrossoverPoint(l2);
}

double Triangle::GetInscribedRadius()
{
	return GetArea() / GetPerimeter();
	
}

double Triangle::GetCircumscribedRadius()
{
	Line a (arc[0], arc[1]), b (arc[0], arc[2]), c (arc[1], arc[2]);
	return (a.GetLength() * b.GetLength() * c.GetLength()) / (4 * GetArea());
}

double Triangle::GetPerimeter() const
{
	Line a (arc[0], arc[1]), b (arc[0], arc[2]), c (arc[1], arc[2]);
	return (a.GetLength() + b.GetLength() + c.GetLength()) / 2;
}