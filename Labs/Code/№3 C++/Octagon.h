#pragma once
#include "shape.h"
class Octagon :
	public Shape
{
public:

	virtual double GetArea() { return 0; };
	virtual Point GetCenterOfGravity() { return Point(0, 0); };
	virtual double GetInscribedRadius() { return 0; };
	virtual double GetCircumscribedRadius() { return 0; };

	Octagon(void);
	~Octagon(void);
};

