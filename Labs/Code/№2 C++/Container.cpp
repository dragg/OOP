#include "Container.h"


Container::Container(void)
{
	next = nullptr;
}

Container::Container(int value_, Container* next_)
{
	value = value_;
	next = next_;
}

Container::~Container(void)
{
}
