#include "Operation.h"

Operation::Operation(void) { }

Operation::~Operation(void) { }

void Operation::Compare(Shape* s1, Shape* s2) const//сравнение фигур следующим условием по их площадям s1 < s2
{
	//Проверка правильности подбора типов фигур
	if((s1->id == 'T' && s2->id == 'S') || (s2->id == 'T' && s1->id == 'S'))
	{
		char sign;
		if(s1->GetArea() < s2->GetArea() && abs(s1->GetArea() - s2->GetArea()) > 0.0001)
		{
			sign = '<';
		}
		else if(s1->GetArea() > s2->GetArea() && abs(s1->GetArea() - s2->GetArea()) > 0.0001)
		{
			sign = '>';
		}
		else
		{
			sign = '=';
		}
		std::cout << "Area " << s1->id << " " << sign << " " << s2->id << std::endl;
	}
	else
	{
		std::cout << "Not such operation" << std::endl;
	}
}

void Operation::IsInclude(Shape* s1, Shape* s2) const
{
	//Проверка правильности подбора типов фигур
	if((s1->id == 'T' && s2->id == 'S') || (s2->id == 'T' && s1->id == 'S'))
	{
		Shape *triagle = s1->id == 'T' ? s1 : s2, *square = s1->id == 'S' ? s1 : s2;
		Line distanceLine(triagle->GetCenterOfGravity(), square->GetCenterOfGravity());
		double distance = distanceLine.GetLength();
		double rT = triagle->GetInscribedRadius(), rS = square->GetInscribedRadius();
		if (distance < abs(rS - rT))
		{
			cout << "Shape " << (s1->GetArea() > s2->GetArea() ? s1->id : s2->id) << " is include " << (s1->GetArea() > s2->GetArea() ? s2->id : s1->id) << endl;
		}
		else
		{
			cout << "Shape " << s1->id << " and " << s2->id << " is not include each other!" << endl;
		}
	}
	else
	{
		std::cout << "Not such operation" << std::endl;
	}
}

void Operation::IsIntersect(Shape* s1, Shape* s2) const
{
	//Проверка правильности подбора типов фигур
	if((s1->id == 'T' && s2->id == 'S') || (s2->id == 'T' && s1->id == 'S'))
	{
		Shape *triagle = s1->id == 'T' ? s1 : s2, *square = s1->id == 'S' ? s1 : s2;
		Line distanceLine(triagle->GetCenterOfGravity(), square->GetCenterOfGravity());
		double RT = triagle->GetCircumscribedRadius(), RS = square->GetCircumscribedRadius(), distance = distanceLine.GetLength();
		double rT = triagle->GetInscribedRadius(), rS = square->GetInscribedRadius();
		cout << "Shape " << s1->id << " and " << s2->id << " is " << (distance <= RT + RS && distance >= abs(rS - rT) ? ("") : ("not ")) << "intersect!" << endl;
	}
	else
	{
		std::cout << "Not such operation" << std::endl;
	}
}