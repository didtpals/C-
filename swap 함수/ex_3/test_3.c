#include <stdio.h>

void swap2(int (*a)[2], int(* b)[2]);

int main(void)
{
	int a[2][2] = { {1,2}, {3,4} };
	int b[2][2] = { {5,6}, {7,8} };

	swap2(&a, &b);

	printf("\n");

	printf("여기는 main함수 입니다.\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", b[i][j]);
		}
	}

	return 0;
}

void swap2(int (*a)[2], int(*b)[2])
{
	int (*temp)[2];

	temp = a;
	a = b;
	b = temp;

	printf("여기는 swap함수 입니다.\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	printf("\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", b[i][j]);
		}
	}
}