#include <stdio.h>

typedef struct
{
	int a;
	char *b;
	double c;
} Object;

void setObject(Object * p);

int main(void)
{
	Object option = { 1, "one", 3.141592 };

	Object* ptr = &option;

	printf("%d %s %.2f\n", ptr->a, ptr->b, ptr->c);

	setObject(&option);

	return 0;
}

void setObject(Object* p)
{
	p->a = 2;
	p->b = "two";
	p->c = 1.736;

	printf("%d %s %.2f\n", p->a, p->b, p->c);
}