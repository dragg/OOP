#include "Stack.h"


CStack::CStack(void)
{
}

CStack::~CStack(void)
{
}

void CStack::push(int value_)
{
	if (head != nullptr)
	{
		Container* tmp = new Container(value_, tail);
		tail = tmp;
	}
	else
	{
		head = new Container(value_, nullptr);
		tail = head;
	}
}

int CStack::pop()
{
	int response;
	if (tail != nullptr)
	{
		response = tail->value;
		Container* tmp = tail;
		tail = tail->next;
		delete tmp;
	}
	return response;
}

bool CStack::empty()
{
	if (tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}