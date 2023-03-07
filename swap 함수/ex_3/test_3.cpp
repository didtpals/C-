#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;

	const int* p = &a; // 포인터 p가 참조하는 값을 바꿀 수 없음. 다만 새로운 변수를 참조할 수 있다.
	int* const q = &b; // 포인터 q가 참조하는 대상을 바꿀 수 없음. q가 참조하는 값은 바꿀 수 있다.

	printf("%d\n", *p);
	a = 20;
	printf("%d\n", *p);

	printf("%d\n", *q);

	return 0;
}