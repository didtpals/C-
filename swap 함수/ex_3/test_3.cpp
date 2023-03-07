#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;

	const int* p = &a; // ������ p�� �����ϴ� ���� �ٲ� �� ����. �ٸ� ���ο� ������ ������ �� �ִ�.
	int* const q = &b; // ������ q�� �����ϴ� ����� �ٲ� �� ����. q�� �����ϴ� ���� �ٲ� �� �ִ�.

	printf("%d\n", *p);
	a = 20;
	printf("%d\n", *p);

	printf("%d\n", *q);

	return 0;
}