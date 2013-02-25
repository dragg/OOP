#include "FactoryShape.h"


FactoryShape::FactoryShape(void)
{
}

FactoryShape::~FactoryShape(void)
{
}

Shape* FactoryShape::Generator()
{
	switch (rand() % 7)
	{
	case 0:
		return new Hexagon();
	case 1:
		return new Octagon();
	case 2:
		return new Parallelogram();
	case 3:
		return new Rectangle();
	case 4: 
		return new Square(Point(0, 0), Point(0, 4), Point(4, 4), Point(4, 0));
	case 5:
		return new Trapeze();
	case 6:
		return new Triangle(Point(1, 1), Point(1, 3), Point(2, 3));
	default:
		break;
	}
}

Shape* FactoryShape::Choice()
{
	char _continue = 'y';
	Shape* tmp = 0;
	while (_continue == 'y')
	{
		tmp = Generator();
		std::cout << "This shape is " << tmp->id << std::endl;
		std::cout << "Continue choice? (y/...)" << std::endl;
		std::cin >> _continue;
	}
	return tmp;
}