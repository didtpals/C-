//#include <stdio.h>
//
//struct hobby // ����ü �������� ���
//{
//	char bill[5];
//	char boll[10];
//};
//
//struct birth // ����ü �ȿ� �Լ� �ֱ�
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
//	typedef char string[]; // ����ü ���
//	typedef int num;
//
//	struct point // ����ü ���
//	{
//		char x[10];
//		char y[10];
//		int z;
//	};
//
//	string name = "�缼��";
//	num age = 20;
//
//	point p = { "���ʱ�", "����", 1 };
//	hobby b = { "�籸", "����" };
//
//	hobby* ptr_b = &b; // ����ü�� �ּ� ���� �����͸� ����� ������
//
//	birth day = { 2004, 05, 14 };
//	day.birth_y();
//	day.birth_m();
//	day.birth_d();
//
//	printf("�̸� : %s\n", name);
//	printf("���� : %d\n", age);
//	printf("������� : %d. %02d. %d\n", day.yy, day.mm, day.dd);
//	printf("�ּ� : %s %s%d��\n", p.x, p.y, p.z); // ����ü ���� ������ ( . )�� ����� �����ؼ� ������
//	printf("��� : %s, %s\n", ptr_b->bill, ptr_b->boll); // ����ü ���� ������ �ּ� ���� ( -> )�� ����� �����ؼ� ������
//	average(&b, 200, 150);
//}
//
//void average(hobby* m, int bill_avr, int boll_aver) // ����ü �����͸� �Լ� �Ķ���ͷ� ���
//{
//	printf("�������� : %s = %d, %s = %d\n", m->bill, bill_avr, m->boll, boll_aver);
//}