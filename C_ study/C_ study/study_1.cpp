#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayanimal[4][5];
int checkanimal[4][5];
const char * stranimal[10];

void initanimalarray();
void initanimalname();
void shuffleanimal();
int getemptyposition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printanimals();
void printauestion();
int foundallanimals();


int main_1(void)
{
	srand(time(NULL));

	initanimalarray();
	initanimalname();
	shuffleanimal();

	int failcount = 0;

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		printanimals();
		printauestion();
		printf("������ ī�带 2�� ������. : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
			continue;

		int firstselect_x = conv_pos_x(select1);
		int firstselect_y = conv_pos_x(select1);

		int secondelect_x = conv_pos_x(select1);
		int secondelect_y = conv_pos_x(select1);

		if ((checkanimal[firstselect_x][firstselect_y] == 0 && checkanimal[secondelect_x][secondelect_y] == 0) && (arrayanimal[firstselect_x][firstselect_y] == arrayanimal[secondelect_x][secondelect_y]))
		{
			printf("\n\n����! : %s �߰�", stranimal[arrayanimal[firstselect_x][firstselect_y]]);
			checkanimal[firstselect_x][firstselect_y] = 1;
			checkanimal[secondelect_x][secondelect_y] = 1;
		}
		else
		{
			printf("\n\n �� ! (Ʋ�Ȱų� �̹� ������ ī��)\n");
			printf("%d : %s\n", select1, stranimal[arrayanimal[firstselect_x][firstselect_y]]);
			printf("%d : %s\n", select2, stranimal[arrayanimal[secondelect_x][secondelect_y]]);
			printf("\n\n");

			failcount++;
		}
		if (foundallanimals() == 1)
		{
			printf("\n\n �����մϴ�. ");
			printf("���ݱ��� �� Ʋ�� Ƚ���� %d �Դϴ�.", failcount);
		}
	}
	return 0;
}

void initanimalarray() 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayanimal[i][j] = -1;
		}
	}
}




void initanimalname()
{
		stranimal[0] = "������";
		stranimal[1] = "�ϸ�";
		stranimal[2] = "������";
		stranimal[3] = "�����";
		stranimal[4] = "����";
		stranimal[5] = "�ڳ���";
		stranimal[6] = "�⸰";
		stranimal[7] = "��Ÿ";
		stranimal[8] = "Ÿ��";
		stranimal[9] = "ȣ����";
}

void shuffleanimal()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getemptyposition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayanimal[x][y] = i;
		}
	}
}

int getemptyposition()
{
	while (1)
	{
		int randpos = rand() % 20;
		int x = conv_pos_x(randpos);
		int y = conv_pos_y(randpos);

		if (arrayanimal[x][y] == -1)
		{
			return randpos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printanimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", stranimal[arrayanimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n===========================================\n");
}
void printauestion()
{
	printf("\n\n(����)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkanimal[i][j] != 0)
			{
				printf("%8s", stranimal[arrayanimal[i][j]]);
			}
			else
			{
				printf("%8s", seq);
			}
		}
	}
}

int foundallanimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkanimal[i][j] == 0)
				return 0;
		}
	}
	return 1;
}