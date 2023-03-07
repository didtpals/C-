#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int rear = -1;
int front = -1;

void enqueue(int value) {
	queue[++rear] = value;
	if (front == -1) {
		front = 0;
	}
	printf("rear : %d\n", rear);
	printf("value : %d\n", value);
	printf("queue[rear] : %d\n", queue[rear]);
}

int dequeue() {
	printf("front : %d\n", front);
	printf("queue[front] : %d\n", queue[front]);

	return queue[front++];
}

int main(void) {
	enqueue(1);
	enqueue(2);

	printf("return : %d\n", dequeue());
	printf("return : %d\n", dequeue());

	printf("queue[0] : %d\n", queue[0]);
	printf("queue[1] : %d\n", queue[1]);

	return 0;
}