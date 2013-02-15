#include "Line.h"

Line::Line(Point A_, Point B_)
{
	A = A_;
	B = B_;
}

double Line::GetLength()
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

Point Line::GetCentralPoint()
{
	return Point((A.x + B.x) / 2, (A.y + B.y) / 2);
}

Point Line::GetCrossoverPoint(Line line)
{
	double a = -line.Get_k(), b = line.A.x == line.B.x ? 0 : 1, c = -line.Get_b();
	double a1 = -this->Get_k(), b1 = A.x == B.x ? 0 : 1, c1 = -this->Get_b();
	if ((a * a1 + b * b1) == 0)
	{
		return Point(-c1, -c);
	}
	else
	{
		return Point((c1 * b - c * b1) / (a * b1 - a1 * b), (c1 * a - c * a1) / (b * a1 - b1 * a));
	}
	
}

double Line::Get_b()
{
	return (A.y - Get_k() * A.x);
}

double Line::Get_k()
{
	if (A.x - B.x != 0)
	{
		if (A.y != B.y)
		{
			return (A.y - B.y) / (A.x - B.x);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
}

Line::~Line(void) { }