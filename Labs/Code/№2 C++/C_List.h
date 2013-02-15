#include "Container.h"

#pragma once
class C_List
{
protected:
	Container* head;
	Container* tail;
public:
	virtual void push(int) = 0;
	virtual int pop() = 0;
	virtual bool empty() = 0;
	C_List(void);
	~C_List(void);
};

