#include <stdio.h>

typedef struct
{
	int id;
	char* name;
	double height;
} Swap;

void swap(Swap* a, Swap* b);

int main(void)
{
	Swap option1 = { 1, "양세민", 219.7 };
	Swap option2 = { 2, "조원준", 232.3 };

	printf("main함수 출력\n");

	printf("아이디 : %d 이름 : %s 키 : %.1f\n", option1.id, option1.name, option1.height);
	printf("아이디 : %d 이름 : %s 키 : %.1f\n", option2.id, option2.name, option2.height);

	swap(&option1, &option2);

	printf("swap함수 출력\n");

	printf("아이디 : %d 이름 : %s 키 : %.1f\n", option1.id, option1.name, option1.height);
	printf("아이디 : %d 이름 : %s 키 : %.1f\n", option2.id, option2.name, option2.height);

	return 0;
}

void swap(Swap* a, Swap* b)
{
	Swap temp;

	temp = *a;
	*a = *b;
	*b = temp;
}