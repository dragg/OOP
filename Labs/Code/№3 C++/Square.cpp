#include "Square.h"

void Square::Init()
{
	arc = new Point[4];
	id = 'S';
}

Square::Square(Point A, Point B, Point C, Point D)
{
	Init();
	arc[0] = A;
	arc[1] = B;
	arc[2] = C;
	arc[3] = D;
}

Square::operator bool() const
{
	Line d1(arc[0], arc[2]), d2(arc[1], arc[3]);
	if (d1.GetLength() == d2.GetLength())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Square::Square(void)
{
	Init();
}

double Square::GetArea()
{
	double a = this->GetA();
	return a * a;
}

Point Square::GetCenterOfGravity()
{
	Line line(arc[0], arc[2]);
	return line.GetCentralPoint();
}

double Square::GetInscribedRadius()
{
	return this->GetA() / 2;
}

double Square::GetCircumscribedRadius()
{
	Line line(arc[0], arc[1]);
	return line.GetLength() / 2;
}

double Square::GetA() const
{
	Line line(arc[0], arc[1]);
	return line.GetLength() / sqrt(2);
}

Square::~Square(void)
{
	delete []arc;
}