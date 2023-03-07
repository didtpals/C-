#include <stdio.h>

int sum_function(int value1, int value2);

int main(void)
{
	int a = 1;
	int b = 2;

	printf("%d", sum_function(a, b));

	return 0;
}

int sum_function(int value1, int value2)
{
	int result;

	result = value1 + value2;

	return result;
}