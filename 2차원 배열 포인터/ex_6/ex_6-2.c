#include <stdio.h>

int odd(int value);
int even(int value);
void count(int* a, int size, int (*p)(int));

int main(void)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("Â¦¼ö : ");
	count(a, 10, odd);

	printf("\n");

	printf("È¦¼ö : ");
	count(a, 10, even);

	return 0;
}

void count(int* a, int size, int (*p)(int))
{
	for (int i = 0; i < size; i++)
	{
		if (p(a[i]))
		{
			printf("%d ", a[i]);
		}
	}
}

int odd(int value)
{
	if (value % 2 == 0)
	{
		return 1;
	}
	return 0;
}

int even(int value)
{
	if (value % 2 == 1)
	{
		return 1;
	}
	return 0;
}