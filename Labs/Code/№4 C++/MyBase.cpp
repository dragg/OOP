#include "MyBase.h"


MyBase::MyBase(void)
{
}

MyBase::~MyBase(void)
{
}

void MyBase::Out()
{
	Out(cout);
	OutFile();
}

void MyBase::Out(ostream &out)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].AverageMark() > 4)
		{
			out << students[i] << endl;
		}
	}
}

void MyBase::OutFile(string path)
{
	try
	{
		fstream out(path, ios::out | ios::trunc);
		if (!out)
		{
			throw (string)"Error open and write";
		}
		Out(out);
	}
	catch(string error)
	{
		cout << error << endl;
		cout << "Chech path output, attr file and try do this operation later!" << endl;
	}
	
}

void MyBase::In(int n, istream &in)
{
	Student tmp;
	if (n == -1)
	{
		while (!in.eof())
		{
			in >> tmp;
			students.push_back(tmp);
		}
	}
	else
	{
		int size = students.size();
		students.resize(n + size);
		for (int i = 0; i < n; i++)
		{
			if(!in.eof())
			{
				in >> tmp;
				students[i] = Student(tmp);
			}
			else
			{
				throw (string)"End the file! Input cann't be!";
			}
		}
	}
	
}

void MyBase::InFile(int n, string path)
{
	fstream in;
	try
	{
		in.open(path, ios::in);
		if (!in)
		{
			throw (string)"Error open and read";
		}
		In(n, in);
		
	}
	catch(string error)
	{
		cout << error << endl;
		cout << "Chech path input and try do this operation later!" << endl;
	}
	in.close();
}

void MyBase::Sort()
{
	sort(students.begin(), students.end());
}