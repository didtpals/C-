#include <stdio.h>

typedef struct Calendar
{
	char week[50] = {"�Ͽ��� ������ ȭ���� ������ ����� �ݿ��� �����"};
	int year;
	int month[20] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int date[50] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
};

int Calender_year(Calendar count);
int Calender_Count(Calendar count);

int main(void)
{
	Calendar count;

	Calender_Count(count);

	return 0;
}

int Calender_year(Calendar count)
{
	while (1)
	{
		printf("�⵵�� �Է��ϼ��� : ");
		scanf_s("%d", &count.year);

		if (count.year > 1900 && count.year < 2100)
		{
			break;
		}
		else
		{
			printf("�������� �ʴ� �⵵�Դϴ�.\n�ٽ� �Է��� �ּ���.\n\n");
		}
	}
	printf("\n\n%60d��\n\n", count.year);
 
	return 0;
}

int Calender_Count(Calendar count)
{
	Calender_year(count);

	for (int month = 0; month < 12; month++)
	{
		printf("%58d��\n\n", count.month[month]);
		printf("                                  ");
		for (int week = 0; week < 1; week++)
		{
			printf("%s\n", &count.week[week]);
			printf("                              ");
			for (int day = 0; day < 31; day++) 
			{
				if (day % 7 == 0) 
				{
					printf("\n\n");
					printf("                              ");
				}
				printf("%7d", count.date[day]);
			}
			printf("\n\n");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}