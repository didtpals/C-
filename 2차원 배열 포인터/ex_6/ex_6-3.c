#include <stdio.h>

int main(void)
{
	int a = 10;
	int* p = &a;
	int** pp = &p;

	printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d\n", p);
	printf("%d\n", &p);
	printf("%d\n", *p);
	printf("%d\n", pp);
	printf("%d\n", &pp);
	printf("%d\n", *pp);
	printf("%d\n", **pp);

	return 0;
}