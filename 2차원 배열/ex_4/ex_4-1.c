//#include <stdio.h>
//
//void swap(int(*a)[3][3], int(*b)[3][3]);
//
//int main(void)
//{
//	int	a[3][3][3] = { {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}, {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}} };
//	int	b[3][3][3] = { {{28, 29, 30}, {31, 32, 33}, {34, 35, 36}}, {{37, 38, 39}, {40, 41, 42}, {43, 44, 45}}, {{46, 47, 48}, {49, 50, 51}, {52, 53, 54}} };
//
//
//
//	printf("main함수 출력\n");
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int x = 0; x < 3; x++)
//			{
//				printf("%d ", a[i][j][x]);
//			}
//		}
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int x = 0; x < 3; x++)
//			{
//				printf("%d ", b[i][j][x]);
//			}
//		}
//	}
//
//	printf("\n\n");
//
//	swap(&a, &b);
//
//	printf("\n\n");
//
//	printf("swap함수 이후 main함수 출력\n");
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int x = 0; x < 3; x++)
//			{
//				printf("%d ", a[i][j][x]);
//			}
//		}
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int x = 0; x < 3; x++)
//			{
//				printf("%d ", b[i][j][x]);
//			}
//		}
//	}
//
//	return 0;
//}
//
//void swap(int(*a)[3][3], int(*b)[3][3])
//{
//	int(*temp)[3][3];
//
//	temp = a;
//	a = b;
//	b = temp;
//
//	printf("swap함수 출력\n");
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int x = 0; x < 3; x++)
//			{
//				printf("%d ", a[i][j][x]);
//			}
//		}
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int x = 0; x < 3; x++)
//			{
//				printf("%d ", b[i][j][x]);
//			}
//		}
//	}
}