//#include <stdio.h>
//
//int arr_function(int(*ptr)[3]);
//
//int main(void)
//{
//	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
//
//	arr_function(arr); // int (*ptr)[3] = arr;
//	 
//	// row가 세칸을 한 배열로 가지고 있기 때문에 col은 한 배열의 0번째부터 값을 채움
//	//for row = [][][]
//	//for col = [1][2][3]
//	//for row = [1][2][3]
//	//              [][][]
//	//for col =  [1][2][3]
//	//             [4][5][6]
//	
//	for (int(*row)[3] = arr; row < arr + 2; row++)
//	{
//		for (int *col = *row; col < *row + 3; col++)
//		{
//			printf("%d ", *col);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//int arr_function(int(*ptr)[3])
//{
//
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", ptr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	printf("%p\n\n", ptr[0]);
//	printf("%p\n\n", ptr[1]);
//	printf("%p\n\n", ptr[2]);
//
//	return 0;
//}

//#include <stdio.h>
//#include <windows.h>
//
//void coller();
//int number_sum(int b);
//int number_multiply(int c);
//
//int main(void)
//{
//	int a;
//	int result;
//
//	coller();
//
//	printf("숫자를 입력하세요. : ");
//	scanf_s("%d", &a);
//
//	Sleep(1000);
//	result = number_sum(a);
//
//	Sleep(1000);
//	number_multiply(result);
//
//	return 0;
//}
//
//void coller()
//{
//	printf("----------------------start-------------------\n\n");
//}
//
//int number_sum(int b)
//{
//	int sum = 0;
//	printf("숫자 %d를 반환 받았습니다.\n", b);
//	for (int i = 1; i <= b; i++)
//	{
//		sum = sum + i;
//	}
//	printf("반환 받은 숫자 %d의 총 합은 %d입니다.\n\n", b, sum);
//
//	return sum;
//}
//
//int number_multiply(int c)
//{
//	int multiply;
//
//	printf("반환 받은 값은 %d입니다.\n", c);
//	printf("반환 값과 곱하고자 하는 값을 입력하시오. : ");
//	scanf_s("%d", &multiply);
//
//	Sleep(1000);
//	printf("반환 받은 값을 곱하면 %d * %d = %d 입니다.\n", c, multiply, c * multiply);
//
//	return 0;
//}