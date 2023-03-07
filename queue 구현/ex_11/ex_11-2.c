#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 100 // ť�� �ִ� ũ��

int queue[QUEUE_MAX_SIZE]; // ť�� ������ �迭
int front = -1; // ť�� �� �� �ε���
int rear = -1; // ť�� �� �� �ε���

void enqueue(int value) {
    if (rear == QUEUE_MAX_SIZE - 1) { // ť�� ���� ���ִ� ���
        printf("Queue Overflow\n");
        return;
    }
    else {
        queue[++rear] = value; // Rear�� ������Ű�� ���� ����
        if (front == -1) { // ť�� ����ִ� ���
            front = 0;
            printf("enqueue : %d\n", queue[rear]);
        }
    }
}

int dequeue() {
    if (front == -1 || front > rear) { // ť�� ����ִ� ���
        printf("\nQueue Underflow\n");
        exit(1);
    }
    else {
        printf("dequeue : %d\n", queue[front]);
        return queue[front++]; // Front�� ������Ű�� ���� ��ȯ
    }
}

int main(void) {
    enqueue(1);
    enqueue(2);
    printf("%d\n ", dequeue()); // 1
    enqueue(3);
    printf("%d\n", dequeue()); // 2
    enqueue(4);
    enqueue(5);

    printf("%d\n", dequeue()); // 3
    printf("%d\n", dequeue()); // 4
    printf("%d\n", dequeue()); // 5

    printf("%d ", dequeue()); // Queue Underflow

    return 0;
}