#pragma once
struct elem
{
	double val;
	elem* next = nullptr;
};

void push(elem*& stack, double value);
bool pop(elem*& stack, double& value);