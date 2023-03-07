#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* arr;
	int rear;
	int front;
	int count;
	int capacity;
} queue; 

void init(queue* que, int size) {
	que->capacity = size;
	que->count = que->front = que->rear = 0;
	que->arr = (int*)malloc(size * sizeof(int));
}

void enqueue(queue* que, int data) {
	que->arr[que->rear] = data;
	que->rear++;
	que->count++;

	if (que->rear >= que->capacity) {
		que->rear = 0;
	}
}

void dequeue(queue* que) {
	que->front++;
	que->count--;

	if (que->front >= que->capacity) {
		que->front = 0;
	}
}

void display(queue* que) {
	int index;
	for (int i = 0; i < que->count; i++) {
		index = (que->front + i) / que->capacity;
		printf("%d", que->arr[index]);
	}
}

int main(void) {
	queue que;
	int num;

	scanf_s("%d", &num);

	init(&que, num);
	enqueue(&que, num);
	display(&que);
	dequeue(&que);
}