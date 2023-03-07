#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // ť�� �ִ� ũ��

int queue[MAX_SIZE]; // ť�� ������ �迭
int front = -1; // ť�� �� �� �ε���
int rear = -1; // ť�� �� �� �ε���

void enqueue(int value) {
	if (rear == MAX_SIZE - 1) { // ť�� ���� ���ִ� ���
		printf("Queue Overflow\n");
		exit(1);
	}
	else
	{
		queue[++rear] = value; // rear�� ������Ű�� ���� ����
		printf("rear : %d\n", rear);
		if (front == -1) { // ť�� ����ִ� ���
			front = 0;
		}
	}
}

int dequeue() {
	if (front == -1 || front > rear) { // ť�� ����ִ� ���
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		printf("front : %d\n", front);
		return queue[front++]; // front�� ������Ű�� ���� ��ȯ
	}
}

int main(void) {
	enqueue(1);
	enqueue(2);

	printf("value : %d\n", dequeue()); // 1
	printf("value : %d\n", dequeue()); // 2

	enqueue(3);
	enqueue(4);

	printf("value : %d\n", dequeue()); // 3
	printf("value : %d\n", dequeue()); // 4
	
	printf("%d\n", dequeue()); //Queue Underflow

	return 0;
}