#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // 큐의 최대 크기

int queue[MAX_SIZE]; // 큐를 저장할 배열
int front = -1; // 큐의 맨 앞 인덱스
int rear = -1; // 큐의 맨 뒤 인덱스

void enqueue(int value) {
	if (rear == MAX_SIZE - 1) { // 큐가 가득 차있는 경우
		printf("Queue Overflow\n");
		exit(1);
	}
	else
	{
		queue[++rear] = value; // rear을 증가시키고 값을 저장
		printf("rear : %d\n", rear);
		if (front == -1) { // 큐가 비어있는 경우
			front = 0;
		}
	}
}

int dequeue() {
	if (front == -1 || front > rear) { // 큐가 비어있는 경우
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		printf("front : %d\n", front);
		return queue[front++]; // front를 증가시키고 값을 반환
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