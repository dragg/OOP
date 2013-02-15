#pragma once
#include "c_list.h"
class CStack :
	public C_List
{
public:
	void push(int item);
	int pop();
	bool empty();
	CStack(void);
	~CStack(void);
};

