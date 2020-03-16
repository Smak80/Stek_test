#include "stek.h"

void push(elem*& stack, double value)
{
	elem* newel = new elem;
	newel->val = value;
	if (stack)
	{
		newel->next = stack;	
	}
	stack = newel;
}

bool pop(elem*& stack, double& value)
{
	if (!stack) return false;
	value = stack->val;
	elem* rem = stack;
	stack = stack->next;
	delete rem;
	return true;
}