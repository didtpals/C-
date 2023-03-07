#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
	int next_rear = (rear + 1) % MAX_SIZE;

	if (next_rear == front) {
		printf("Queue Qverflow\n");
		exit(1);
	}
	else
	{
		queue[rear] = value;
		rear = next_rear;
		printf("next_rear : %d\n", next_rear);
		printf("rear : %d\n", rear);
		printf("rear_value : %d\n", value);
	}
}

int dequeue() {
	if (front == rear) {
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		int value = queue[front];
		front = (front + 1) % MAX_SIZE;
		printf("front : %d\n", front);
		printf("front_value : %d\n", value);
		return value;
	}
}

int main(void) {
	enqueue(1);
	printf("------------- return_value : %d -------------\n", dequeue()); // 1
	enqueue(2);
	printf("------------- return_value : %d -------------\n", dequeue()); // 2
	enqueue(3);
	printf("------------- return_value : %d -------------\n", dequeue()); // 3
	enqueue(4);
	printf("------------- return_value : %d -------------\n", dequeue()); // 4
	enqueue(5);
	printf("------------- return_value : %d -------------\n", dequeue()); // 5
	enqueue(6);
	printf("------------- return_value : %d -------------\n", dequeue()); // 6
	enqueue(7);
	printf("------------- return_value : %d -------------\n", dequeue()); // 7
	enqueue(8);
	printf("------------- return_value : %d -------------\n", dequeue()); // 8
	enqueue(9);
	printf("------------- return_value : %d -------------\n", dequeue()); // 9
	enqueue(10);
	printf("------------- return_value : %d -------------\n", dequeue()); // 10

	printf("%d\n", dequeue()); //Queue Underflow

	return 0;
}