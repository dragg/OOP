#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

#pragma once
class MyBase
{
private:
	vector<Student> students;
public:
	void Sort();//сортировка по номеру группы
	void In(int n, istream& in);//ввод данных с указанного потока
	void InFile(int n = -1, string path = "BaseIn.txt");//ввод данных с указанного файла
	void Out();//Вывод на экран и в файл студентов, средний балл которых больше 4
	void Out(ostream& out);//вывод списка студентов в указанный поток
	void OutFile(string path = "BaseOut.txt");//вывод списка студентов в указанный файл
	MyBase(void);
	~MyBase(void);
};

