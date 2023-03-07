#include <stdio.h>
#include <string.h>

void swap(char* type, void* a, void* b);

int main(void)
{
	int ia = 10;
	int ib = 20;
	char ca[10] = "yangsemin";
	char cb[10] = "kimjungho";

	printf("swap Àü\n");

	printf("a == %d\nb == %d\n", ia, ib);
	printf("a == %s\nb == %s\n\n", ca, cb);

	printf("swap ÈÄ\n");

	swap("int", &ia, &ib);
	printf("a == %d\nb == %d\n", ia, ib);

	swap("char", ca, cb);
	printf("a == %s\nb == %s\n", ca, cb);

	return 0;
}

void swap(char* type, void* a, void* b)
{
	int it;
	char ct;

	if (strcmp(type, "int") == 0)
	{
		it = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = it;
	}
	else if (strcmp(type, "char") == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			ct = ((char*)a)[i];
			((char*)a)[i] = ((char*)b)[i];
			((char*)b)[i] = ct;
		}
	}
}