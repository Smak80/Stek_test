#include <iostream>
#include "cgi.h"
#include "stek.h"

using namespace std;

void create_stack(elem*& stack, const char* data)
{
	char* str = _strdup(data);
	char* tmp = str;
	char* cont;
	while (char* part = strtok_s(tmp, "; ", &cont))
	{
		tmp = nullptr;
		double x;
		sscanf_s(part, "%lf", &x);
		push(stack, x);
	}
}

void show_stack(elem*& stack)
{
	double val;
	while (pop(stack, val))
	{
		cout << val << "<br>";
	}
}

void main()
{
	cout << "Content-type: text/html; charset=Winows-1251\n\n";
	cout << "<form action='stack.cgi' method='get'>";
	cout << "Последовательность: <input type='text' name='series'><br>";
	cout << "<input type='submit' value='Отправить'>";
	cout << "</form>";
	char* data = nullptr;
	get_form_data(data);
	char* series;
	get_param_value(series, "series", data);
	//series = "3.5; 2.44; -5.68; -3.14; 5.11";
	elem* stack = nullptr;
	create_stack(stack, series);
	show_stack(stack);
	delete[] data;
	
}