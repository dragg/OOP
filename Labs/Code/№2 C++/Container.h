#pragma once
class Container
{
public:
	int value;
	Container* next;
	Container(void);
	Container(int value_, Container* next_);
	~Container(void);
};

