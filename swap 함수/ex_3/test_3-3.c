#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;

	const int* pa = &a;
	int* const pb = &b;

	printf("%d", pa);
	*pa = 20;

	printf("%d", pb);
	*pb = &a;
}