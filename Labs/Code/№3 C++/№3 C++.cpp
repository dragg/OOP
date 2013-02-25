#include <iostream>
#include "Triangle.h"
#include "Square.h"
#include "Operation.h"
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "FactoryShape.h"
using namespace std;

int main()
{
	Shape *shape1, *shape2;//создание 2х указателей на базовый класс
	FactoryShape f;//создание фабрики фигур
	Operation oper;//создание экземпляра класса для операций над фигурами
	shape1 = f.Choice();//выбор 1й фигуры
	shape2 = f.Choice();//выбор 2й фигуры
	oper.Compare(shape1, shape2);//выполнение операции сравнения
	oper.IsIntersect(shape2, shape1);//проверка пересечения фигур
	oper.IsInclude(shape2, shape1);//проверка включения фигур друг в друга
	return 0;
}