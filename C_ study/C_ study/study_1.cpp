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
		printf("뒤집을 카드를 2개 고르세요. : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
			continue;

		int firstselect_x = conv_pos_x(select1);
		int firstselect_y = conv_pos_x(select1);

		int secondelect_x = conv_pos_x(select1);
		int secondelect_y = conv_pos_x(select1);

		if ((checkanimal[firstselect_x][firstselect_y] == 0 && checkanimal[secondelect_x][secondelect_y] == 0) && (arrayanimal[firstselect_x][firstselect_y] == arrayanimal[secondelect_x][secondelect_y]))
		{
			printf("\n\n빙고! : %s 발견", stranimal[arrayanimal[firstselect_x][firstselect_y]]);
			checkanimal[firstselect_x][firstselect_y] = 1;
			checkanimal[secondelect_x][secondelect_y] = 1;
		}
		else
		{
			printf("\n\n 땡 ! (틀렸거나 이미 뒤집힌 카드)\n");
			printf("%d : %s\n", select1, stranimal[arrayanimal[firstselect_x][firstselect_y]]);
			printf("%d : %s\n", select2, stranimal[arrayanimal[secondelect_x][secondelect_y]]);
			printf("\n\n");

			failcount++;
		}
		if (foundallanimals() == 1)
		{
			printf("\n\n 축하합니다. ");
			printf("지금까지 총 틀린 횟수는 %d 입니다.", failcount);
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
		stranimal[0] = "원숭이";
		stranimal[1] = "하마";
		stranimal[2] = "강아지";
		stranimal[3] = "고양이";
		stranimal[4] = "돼지";
		stranimal[5] = "코끼리";
		stranimal[6] = "기린";
		stranimal[7] = "낙타";
		stranimal[8] = "타조";
		stranimal[9] = "호랑이";
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
	printf("\n\n(문제)\n");
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