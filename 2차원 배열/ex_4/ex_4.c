#include <stdio.h>

void swap(int(*a)[3], int(*b)[3]);

int main(void)
{
	int	a[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int	b[2][3] = { {7, 8, 9}, {10, 11, 12} };

	printf("main함수 출력\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	printf("\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", b[i][j]);
		}
	}

	printf("\n\n");

	swap(&a, &b);

	return 0;
}

void swap(int(*a)[3], int(*b)[3])
{
	int(*temp)[3];

	temp =   a;
	a = b;
	b = temp;

	printf("swap함수 출력\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	printf("\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", b[i][j]);
		}
	}
}