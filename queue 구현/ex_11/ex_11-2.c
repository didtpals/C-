#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 100 // 큐의 최대 크기

int queue[QUEUE_MAX_SIZE]; // 큐를 저장할 배열
int front = -1; // 큐의 맨 앞 인덱스
int rear = -1; // 큐의 맨 뒤 인덱스

void enqueue(int value) {
    if (rear == QUEUE_MAX_SIZE - 1) { // 큐가 가득 차있는 경우
        printf("Queue Overflow\n");
        return;
    }
    else {
        queue[++rear] = value; // Rear를 증가시키고 값을 저장
        if (front == -1) { // 큐가 비어있는 경우
            front = 0;
            printf("enqueue : %d\n", queue[rear]);
        }
    }
}

int dequeue() {
    if (front == -1 || front > rear) { // 큐가 비어있는 경우
        printf("\nQueue Underflow\n");
        exit(1);
    }
    else {
        printf("dequeue : %d\n", queue[front]);
        return queue[front++]; // Front를 증가시키고 값을 반환
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