//#include <stdio.h>
//
//struct hobby // 구조체 전역으로 사용
//{
//	char bill[5];
//	char boll[10];
//};
//
//struct birth // 구조체 안에 함수 넣기
//{
//	int yy, mm, dd;
//
//	void birth_y() { yy; }
//	void birth_m() { mm; }
//	void birth_d() { dd; }
//};
//void average(hobby* m, int bill_avr, int boll_aver);
//
//int main(void)
//{
//	typedef char string[]; // 구조체 사용
//	typedef int num;
//
//	struct point // 구조체 사용
//	{
//		char x[10];
//		char y[10];
//		int z;
//	};
//
//	string name = "양세민";
//	num age = 20;
//
//	point p = { "서초구", "서초", 1 };
//	hobby b = { "당구", "볼링" };
//
//	hobby* ptr_b = &b; // 구조체의 주소 값을 포인터를 사용해 가져옴
//
//	birth day = { 2004, 05, 14 };
//	day.birth_y();
//	day.birth_m();
//	day.birth_d();
//
//	printf("이름 : %s\n", name);
//	printf("나이 : %d\n", age);
//	printf("생년월일 : %d. %02d. %d\n", day.yy, day.mm, day.dd);
//	printf("주소 : %s %s%d동\n", p.x, p.y, p.z); // 구조체 안의 변수를 ( . )을 사용해 구별해서 가져옴
//	printf("취미 : %s, %s\n", ptr_b->bill, ptr_b->boll); // 구조체 안의 변수의 주소 값을 ( -> )을 사용해 구별해서 가져옴
//	average(&b, 200, 150);
//}
//
//void average(hobby* m, int bill_avr, int boll_aver) // 구조체 포인터를 함수 파라미터로 사용
//{
//	printf("에버리지 : %s = %d, %s = %d\n", m->bill, bill_avr, m->boll, boll_aver);
//}