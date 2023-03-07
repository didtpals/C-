//#include <stdio.h>
//
//int function_int_arr(int (*arr)[3]);
//char function_char_arr(char (*ptr)[10]);
//
//int main(void)
//{
//	int arr[2][3] = { {1,2,3}, {4,5,6} };
//	char arr2[6][10] = { "양세민", "김정호", "박준서", "강희원", "이석주", "양종원" };
//
//	function_int_arr(arr);
//	function_char_arr(arr2);
//
//	return 0;
//}
//int function_int_arr(int (*arr)[3])
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	arr[0][0] = 100;
//	arr[0][1] = 200;
//	arr[0][2] = 300;
//	arr[1][0] = 400;
//	arr[1][1] = 500;
//	arr[1][2] = 600;
//
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	return 0;
//}
//
//char function_char_arr(char (*ptr)[10])
//{
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%s ", &ptr[i]);
//	}
//	printf("\n\n");
//
//	return 0;
//}