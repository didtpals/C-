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
//	// row�� ��ĭ�� �� �迭�� ������ �ֱ� ������ col�� �� �迭�� 0��°���� ���� ä��
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
//	printf("���ڸ� �Է��ϼ���. : ");
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
//	printf("���� %d�� ��ȯ �޾ҽ��ϴ�.\n", b);
//	for (int i = 1; i <= b; i++)
//	{
//		sum = sum + i;
//	}
//	printf("��ȯ ���� ���� %d�� �� ���� %d�Դϴ�.\n\n", b, sum);
//
//	return sum;
//}
//
//int number_multiply(int c)
//{
//	int multiply;
//
//	printf("��ȯ ���� ���� %d�Դϴ�.\n", c);
//	printf("��ȯ ���� ���ϰ��� �ϴ� ���� �Է��Ͻÿ�. : ");
//	scanf_s("%d", &multiply);
//
//	Sleep(1000);
//	printf("��ȯ ���� ���� ���ϸ� %d * %d = %d �Դϴ�.\n", c, multiply, c * multiply);
//
//	return 0;
//}