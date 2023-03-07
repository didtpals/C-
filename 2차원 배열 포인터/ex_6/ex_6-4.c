#include <stdio.h>

int main(void)
{
	int a[2][3] = { {1,2,3}, {4,5,6} };
	int(*pa)[3] = a;

	int* p[2][3] = { {1,2,3}, {4,5,6} };
	
	printf("2차원 배열 포인터\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("2차원 포인터 배열\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(p[i]+j));
		}
		printf("\n");
	}

	return 0;
}