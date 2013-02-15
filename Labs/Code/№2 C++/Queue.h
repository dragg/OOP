#pragma once
#include "c_list.h"
class CQueue :
	public C_List
{
public:
	CQueue(void);
	~CQueue(void);
	void push(int value);
	int pop();
	bool empty();
};

