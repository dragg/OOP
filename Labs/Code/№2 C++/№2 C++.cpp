#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	CQueue queue;
	CStack stack;
	
	for (int i = 0; i < 10; i++)
	{
		queue.push(i);
		stack.push(i);
	}

	cout << "Work of the Queue:" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (!queue.empty())
		{
			cout << queue.pop() << ' ';
		}
	}
	cout << endl;
	cout << "Work of the Stack:" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (!stack.empty())
		{
			cout << stack.pop() << ' ';
		}
	}
	return 0;
}

