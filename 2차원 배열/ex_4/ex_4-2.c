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
	Swap option1 = { 1, "�缼��", 219.7 };
	Swap option2 = { 2, "������", 232.3 };

	printf("main�Լ� ���\n");

	printf("���̵� : %d �̸� : %s Ű : %.1f\n", option1.id, option1.name, option1.height);
	printf("���̵� : %d �̸� : %s Ű : %.1f\n", option2.id, option2.name, option2.height);

	swap(&option1, &option2);

	printf("swap�Լ� ���\n");

	printf("���̵� : %d �̸� : %s Ű : %.1f\n", option1.id, option1.name, option1.height);
	printf("���̵� : %d �̸� : %s Ű : %.1f\n", option2.id, option2.name, option2.height);

	return 0;
}

void swap(Swap* a, Swap* b)
{
	Swap temp;

	temp = *a;
	*a = *b;
	*b = temp;
}