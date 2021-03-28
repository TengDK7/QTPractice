#include "Math.h"


int add_d2(int a, int b)
{
	return a + b;
}

int reduce_d2(int a, int b)
{
	return a - b;
}

int multiply_d2(int a, int b)
{
	return a * b;
}

int divide_d2(int a, int b)
{
	return b != 0 ? a / b : 0;
}