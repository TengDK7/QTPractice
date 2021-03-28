#include "Math.h"

int add_d1(int a, int b)
{
	return a+b;
}

int reduce_d1(int a, int b)
{
	return a-b;
}

double reduce_d1(double a, double b)
{
	return a - b;
}

int multiply_d1(int a, int b)
{
	return a*b;
}

int divide_d1(int a, int b)
{
	return b != 0 ? a / b : 0;
}
